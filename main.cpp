#include <iostream>
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

    std::cout<<arr[2]<<" "<<arr[4]<<" "<<arr[9]<<"\n";
    std::cout<<pow(arr[2],3)+pow(arr[4],3)+pow(arr[9],3) << "\n";



    std::cout<<"Part 2"<<"\n";
    std::cout<<"Please, enter number of array's elements: ";
    int n=0;
    std::cin >> n;
    int* arr2 = new int [n-1];

    for (int k=0; k <= n-1; k++)
        std::cin >> arr2[k];

    for (int l=0; l <= n-1; l++)
        std::cout << arr2[l] << " ";

    std::cout<<"\n";

    for (int l=0; l<=n-1; l++ )
        if (l%2 == 0) {
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

    std::cout<<"Your sum: "<<sum;

    delete [] arr2;


    std::cout<<"\nPart 3\n";
    std::vector<int> vec;
    int num;
    int abc;
    std::cout<<" Please, enter number of elements: ";
    std::cin >> num;
    for (int i=0; i<=num - 1; i++) {
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
    for (int i=0; i<=num; i++)
        sum = sum + vec[i];

    std::cout<<"\nVector`s sum: " << sum<<"\n";

    for (int i=0; i<=num; i++)
        if (vec[i]<0) vec.erase(vec.begin()+i);

    for (auto x : vec)
        std::cout<<x<<" ";


    std::cout<<"\nPart 4\nPlease, enter your phrase: ";
    std::string str;

    std::cin.ignore(10, '\n');
    std::getline(std::cin, str);
    std::cout<<str;

    int num_z = 0;
    std::cout<<"\n"<<str.length()<<"\n";
    for (int i=0; i<=str.length(); i++) {
       if (static_cast<char>(str[i]) == 122) num_z++; }
    std::cout<<"Number of z: "<<num_z;

    int l1;
    int l2;
    std::cout<<"\nPlease, enter l1 and l2: ";
    std::cin>>l1;
    std::cin>>l2;
    for (int i = l1-1; i<=l2-1; i++)
        std::cout<<str[i];

    std::cout<<"\nPlease, enter a word: ";
    std::string str4_4;
    std::cin>>str4_4;
    std::string example = "Can you can a can as a canner can can a can?";

    for (int i=0;i<=example.length();i++) {
        if ((example[i] == 67 || example[i] == 99) && (example[i+1]==97) && (example[i+2] == 110) && ((example[i+3]==32) || (example[i+3]==63))) {
            example.replace(i, 3, str4_4);
        }
        }

    std::cout<<"\n"<<example;
    return 0;
}
