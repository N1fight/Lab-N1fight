#include <iostream>
#include <vector>
void displaying(std::vector<int> a) {
    for (int i = 0; i < a.size(); i++) {
        std::cout << a[i] << "\n";
    }
}
class Primer
{
private:
    int m_number;
    std::string m_name;
public:
    Primer(int number, std::string name)
    {
        m_number = number;
        m_name = name;
    }
    void get() {
        std::cout << m_number << " " << m_name << std::endl;
    }
    ~Primer() {}

};
int main()
{
    std::vector <int> array;
    std::vector <Primer> mas;
    int a;
    for (int i = 0; i < 3; i++) {
        std::cin >> a;
        array.push_back(a);
    }
    //erase
    array.erase(array.begin());
    std::cout << "erase" << "\n";
    displaying(array);
    //
    

    // insrert
    array.insert(array.end() - 1, 7);
    std::cout << "insert:" << "\n";
    displaying(array);
    //


    // emplace_back
    mas.emplace_back(7, "Primer");
    for (int i = 0; i < mas.size(); i++) {
        mas[i].get();
    }
    //
  
 
    // push_back
    mas.push_back(Primer(7, "Primer"));
    for (int i = 0; i < mas.size(); i++) 
    {
       mas[i].get();
    }
    //


    // resize
    std::vector <int> primers{ 1,2,3,4,5 };
    std::cout << "resize1" << "\n";
    primers.resize(4);
    displaying(primers);
    std::vector <int> primers1{ 1,2,3 };
    std::cout << "resize2" << "\n";
    primers1.resize(6, 4);
    displaying(primers1);
    //


    //reserve and capacity
    std::cout << "reserve and capacity" << "\n";
    std::vector <int> primers3;

    primers3.push_back(10);
    std::cout << primers3.capacity() << "\n";

    primers3.reserve(10);
    std::cout << primers3.capacity() << "\n";
    //


    //shrink_to_fit
    primers3.shrink_to_fit();
    std::cout << "shrink_to_fit" << "\n";
    std::cout << primers3.capacity() << "\n";
    //


    //clear
    std::cout << "clear" << "\n";
    std::vector<int> primers4{ 1,2,3,4 };
    primers4.clear();
    displaying(primers4);
    //


    //Sizeof
    std::vector<int> primers5;
    primers5.push_back(1);
    std::cout << primers5[0] << "\n";
    primers5[0] = 18;
    std::cout << primers5[0] << "\n";
    std::cout << sizeof(primers5) << "\n";
}