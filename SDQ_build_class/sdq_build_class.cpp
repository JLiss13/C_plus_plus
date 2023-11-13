#include <iostream>
#include <vector>
// Example of how to build a class

using namespace std;
class Company
{
    public:
        int GetNetWorth()
        {
            return m_net_worth;
        }
        
        void SetNetWorth(int value)
        {
            m_net_worth = value;
        }

        std::string m_name;

    private:
        
        double m_net_worth;
};

class ExampleCompany : public Company
{
    public:
        ExampleCompany(std::vector<std::string> _product_names_)
        {
            m_product_names = _product_names_;
            m_name = "ExampleCompany";
        }

    private:
        std::vector<std::string> m_product_names;

};
int main()
{
    std::vector<std::string> product_names = {"Thingy-ma-jig"};
    ExampleCompany* exampleCompany = new ExampleCompany(product_names);
    exampleCompany->SetNetWorth(1000000000); // Trillion dollars
    std::cout << "Example Company is worth= $" << exampleCompany->GetNetWorth() << std::endl;
    return 0;
}