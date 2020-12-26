#include <iostream>
#include <iomanip>
#include <ctime>
#include <cmath>
#include <vector>
#include <string>


int main() {

    std::cout<<"Part 1"<<"\n";
    int arr[10];
    std::srand(std::time(nullptr));

    for (int i=0; i<=9; i++)
        arr[i] = std::rand()%21-10;

    for (int i=0; i<=9; i++)
        std::cout<<arr[i]<<" ";

    std::cout<<"\n";

    std::cout<<arr[2]<<" "<<arr[4]<<" "<<arr[9]<<"\n";
    std::cout<<pow(arr[2],3)+pow(arr[4],3)+pow(arr[9],3) << "\n";

    std::cout << std::setw(45) << std::setfill('=') << '=' << std::endl;
    std::cout<<"Part 2"<<"\n";
    std::cout<<"Please, enter number of array's elements: ";
    int n=0;
    std::cin >> n;
    int* arr2 = new int [n];

    for (int k=0; k <= n-1; k++)
        std::cin >> arr2[k];

    for (int l=0; l <= n-1; l++)
        std::cout << arr2[l] << " ";

    std::cout<<"\n";

    for (int l=0; l<=n-1; l++ )
        if (l%2 == 1) {
            arr2[l]=arr2[l] * 7;
        }

    for (int l=0; l <= n-1; l++)
        std::cout << arr2[l] << " ";
    std::cout<<"\n";

    int k1;
    int k2;
    std::cout<<"Please, enter k1 and k2: \n";
    std::cin>>k1;
    std::cin>>k2;

    int sum = 0;
    for (int l = k1-1; l<=k2-1; l++)
        sum = sum + arr2[l];

    std::cout<<"Your sum: "<< sum << std::endl;

    delete [] arr2;

    std::cout << std::setw(45) << std::setfill('=') << '=' << std::endl;
    std::cout<<"Part 3\n";
    std::vector<int> vec;
    int num, abc;
    std::cout<<"Please, enter number of elements: ";
    std::cin >> num;
    for (int i=0; i < num; i++) {
        std::cin>>abc;
        vec.push_back(abc);
    }

    for (auto x : vec)
        std::cout<<x<<" ";
    std::cout<<'\n';

    vec.push_back(10);
    for (auto x : vec)
        std::cout<<x<<" ";

    sum = 0;
    for (int i = 0; i <= num; i++)
        sum = sum + vec[i];

    std::cout<<"\nVector`s sum: " << sum <<"\n";
    for (int i=0; i <= num; i++) //fixed if (vec[i]<0) 
    {
        if (vec[i] < 0)
        {
            vec.erase(vec.begin()+i);
            break;
        }
    }

    for (auto x : vec)
        std::cout<<x<<" ";

    std::cout << std::endl << std::setw(45) << std::setfill('=') << '=' << std::endl;
    std::cout<<"Part 4\nPlease, enter your phrase: ";
    std::string str;

    std::cin.ignore(10, '\n');
    std::getline(std::cin, str);
    std::cout<<str;

    int num_z = 0;
    std::cout<<"\n"<<str.length()<<"\n";
    for (int i=0; i<=str.length(); i++) {
        if (str[i] == 122) num_z++; }
    std::cout<<"Number of z: "<<num_z;

    int l1, l2;
    std::cout<<"\nPlease, enter l1 and l2: ";
    std::cin>>l1;
    std::cin>>l2;
    std::string str2 = str.substr (l1, l2 - l1 + 1); //fixed
    std::cout << str2; 

    std::cout<<"\nPlease, enter a word: ";
    std::string str4_4;
    std::cin>>str4_4;
    std::string example = "Can you can a can as a canner can can a can?";

    /* //Old implementation
    for (int i=0;i<=example.length()-3;i++) {
        if ((example[i] == 67 || example[i] == 99) && (example[i+1]==97) 
                && (example[i+2] == 110) && ((example[i+3]==32) || (example[i+3]==63))) {

            example.replace(i, 3, str4_4);
        }
    }

    std::cout<<"\n"<<example<<"\n";
    */

    //New one
    std::string mas_str[3] = {"can ", "can?", "Can"};
    for (int j = 0; j < 3; j++)
    {
        int i = 0, pos = example.find(mas_str[j], 0);
        for (pos; (pos = example.find(mas_str[j], i)) != -1; i = pos + 1)
            example.replace(pos, 3, str4_4);
    }

    std::cout << example << std::endl;

    return 0;
}
