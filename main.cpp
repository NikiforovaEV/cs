#include <iostream>
#include <vector>
const size_t MAX_WIDTH = 80;
const size_t MAX_AST = MAX_WIDTH - 4;
using namespace std;

int main()
{
    cerr << "Enter the quantity numbers: " << '\n';
    size_t number_count;
    cin >> number_count;
    vector <double> numbers(number_count);
    cerr << "Enter the number values: " << '\n';
    for(size_t i = 0; i < number_count; i++)
    {
        cin >> numbers[i];
    }
    double res = 1;
    while (res != 0)
    {
        {
            cerr << "Enter the size of bin: " << '\n';
            size_t bin_count;
            cin >> bin_count;
            vector <size_t> bins(bin_count, 0);
            double min = numbers[0];
            double max = numbers[0];
            for(double number : numbers)
            {
                if(number > max)
                {
                    max = number;
                }
                else if(number < min)
                {
                    min = number;
                }
            }
            for(double number : numbers)
            {
                size_t bin_index = (size_t)((number - min) * bin_count / (max - min));
                if (number == max)
                {
                    bin_index--;
                }
                bins[bin_index]++;
            }
            double koeff = 1;
            size_t max_count = 0;
            for(size_t bin : bins)
            {
                if (max_count < bin)
                {
                    max_count = bin;
                }
            }
            if (max_count > MAX_AST)
            {
                koeff = static_cast <double> (MAX_AST) / max_count;
            }
            for(size_t bin : bins)
            {
                if(bin < 100)
                {
                    cout << " ";
                }
                if (bin < 10)
                {
                    cout << " ";
                }
                cout << bin << "|";
                size_t height = bin * koeff;
                for(size_t i = 0; i < height; i++)
                {
                    cout << "*";
                }
                cout << endl;
            }
            cout << "Are you satisfied with the result? Yes(0) or No(1)? ";
            cin >> res;
        }
    }
    return 0;
}
