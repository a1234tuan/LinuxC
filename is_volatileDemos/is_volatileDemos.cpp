#include<iostream>
#include<type_traits>
#include<cstdint>

using namespace std;
//设计一个安全的内存映射寄存器的模版类，可以应用到嵌入式系统或操作系统中，对值的访问过程可以加上is_volatile
//创建一个通用模版类，封装对一个内存地址的读写访问
//C++17/20标准


template<typename T>
class MemoryMappedRegister{
    //写接口
public:
    //构造函数，接受一个内存地址
    explicit MemoryMappedRegister(uintptr_t addr)
        :m_register_addr(reinterpret_cast<volatile T*>(addr))
    {
        static_assert(is_volatile_v<T>,"MemoryMappedRegister must be instantiated with a volatile type"
        "(volatile uint32_t)."
        "This is crucial for accessing hardware registers.");
    }

    //禁止拷贝
    MemoryMappedRegister(const MemoryMappedRegister&) = delete;
    MemoryMappedRegister& operator=(const MemoryMappedRegister&) = delete;
    //读取寄存器值
    T read()const{
        return *m_register_addr;
    }

    //写入寄存器值
    void write(T value){
        *m_register_addr = value;
    }

    //设置特定位
    void set_bits(T mask){
        T current_value = read();
        write(current_value | mask);
    }

    //清除标志位
    void clear_bits(T mask){
        T current_value =read();
        write(current_value & ~mask);
    }

private:
    //存储寄存器内存地址，注意：指针指向的是volatile数据
    volatile T* const m_register_addr;
};

//辅助函数：如何在编译器判断类型特性

template<typename RegType>
void print_register_trait(){
    cout<<"Type:"<<typeid(RegType).name()<<"| is_volatile:"<<boolalpha << is_volatile_v<
    RegType> << endl;
}

int main(){
    cout<<"==========is_volatile实战安全：内存映射寄存器=========="<<endl;
    //类型特性检查
    cout<<"\n========类型特性检查============="<<endl;
    print_register_trait<int>();
    print_register_trait<volatile int>();
    print_register_trait<volatile uint32_t>();

    int *p;
    volatile int* vp;
    print_register_trait<decltype(*p)>();//int
    print_register_trait<decltype(*vp)>();//volatile int 




    //MemoryMappedRegister正确应用
    cout<<"========== 正确使用案例 =========="<<endl;
    constexpr uintptr_t fake_register_address = 0x40021001;//假设
    MemoryMappedRegister<volatile uint32_t> gpio_odr(fake_register_address);
    cout<<"Register at address 0x"<<std::hex<<fake_register_address<<"create successfully."<<dec
    <<endl;
    
 /*   //模拟操作
    uint32_t current_va=gpio_odr.read();//读取
    gpio_odr.write(0x000066FF);//写入
*/


    return 0;
}