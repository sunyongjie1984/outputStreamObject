#include <fstream>
#include <iostream>
#include <string>
int main()
{
    // std::ofstream outfile("hello_world.txt"); // 以输出模式打开
    // 可不可以这样理解，上面的语句定义了一个对象，这是一个文件流对象，这个对象具有方法
    // 就是向自己这个文件中写入对象，outfile << word的意思是，outfile调用自己的函数operator <<向自己写入对象，
    // 对象应该可以是各种类型的，std::string, int,应该都可以，只不过在类std::ofstream中重载了函数operator <<。
    // 扩展对std::cout << "I love china"的理解，std::cout应该是一个在哪里定义的一个全局的iostream对象，说白了
    // 就是在什么地方有这样的一个定义，std::ostream cout(),这个对象是一个标准输出流对象，说白了，有一种动态的机制
    // 把一个控制台的窗口关联到了这个std::cout对象，std::cout << "I love china"一经执行，就像这个控制台窗口，
    // 说白了也就是这个标准输出流对象，写了这样的一个char*字符串，在iostream中也一定为函数opreator << 定义了n多个重载函数。
    std::ofstream outfile("hello_world.txt", std::ios_base::app); // 以附加模式打开

    // 下面如果infile.txt不存在就会报错，可不可以这样理解，std::cin这个对象是可以自动关联到一个控制台窗口的，这个窗口一定
    // 存在，而对于文件的情况，如果这个文件不存在，我们就根本无法读取内容的。我这么理解到这个位置比较牵强，不好，有时间再研究
    std::ifstream infile("infile.txt"); // 将infile.txt中内容附加到hello_world.txt中，infile.txt必须已经被打开，文件不存在
    if (!infile)                        // 会报错
    {
        std::cerr << "error: unable to open input file!\n";
        return -1;
    }
    if (!outfile)
    {
        std::cerr << "error: unable to open output file!\n";
        return -2;
    }
    std::string word;
    while (infile >> word)
    {
        outfile << word << ' ';
    }
    return 0;
}
