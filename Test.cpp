#define CHECK DOCTEST_CHECK
#include "doctest.h"
using namespace doctest;
#include <iostream>
#include <fstream>
#include <sstream>
#include <stdexcept>

#include <ctime>
#include <cstdlib>


#include "Matrix.hpp"
using namespace std;
using namespace zich;




TEST_CASE(" plus and minus")
{
  std::vector<double> vec1 = {1, 0, 0, 0, 1, 0, 0, 0, 1};
  std::vector<double> vec2 = {2, 0, 0, 0, 2, 0, 0, 0, 2};
  std::vector<double> vec3 = {3, 0, 0, 0, 3, 0, 0, 0, 3};
  std::vector<double> vec4 = {0, 0, 0, 0, 0, 0, 0, 0, 0};
  std::vector<double> vec5 = {3, 0, 0, 0, 3, 0, 0, 0};
  std::vector<double> vec6 = {0, 4, 0, 4, 0, 4};

  
  Matrix a{vec1, 3, 3};  // constructor taking a vector and a matrix size
  Matrix b{vec2, 3, 3};  // constructor taking a vector and a matrix size
  Matrix c{vec3, 3, 3};  // constructor taking a vector and a matrix size
  Matrix d{vec4, 3, 3};  // constructor taking a vector and a matrix size
  Matrix e{vec5, 2, 4};  // constructor taking a vector and a matrix size
  Matrix f{vec6, 3, 2};  // constructor taking a vector and a matrix size
  CHECK((c-a)==  b);
  CHECK((c-b)==  a);
  CHECK((a+b)==  c);
  CHECK((a-a)==  d);
  CHECK((b-b)==  d);
  CHECK((c-c)==  d);
  CHECK_THROWS(e+f);
  CHECK_THROWS(e-f);
  CHECK_THROWS(a+f);
  CHECK_THROWS(a-f);
  CHECK_THROWS(b+f);
  CHECK_THROWS(b-f);
  CHECK_THROWS(c+f);
  CHECK_THROWS(c-f);
  CHECK_THROWS(d+f);
  CHECK_THROWS(d-f);
  // CHECK((a+=d)==  a);
  // CHECK((b+=d)==  b);
  // CHECK((c-=d)==  c);
  // CHECK((a-=d)==  a);
  // CHECK((b-=d)==  b);

}


TEST_CASE(" Comparisons")
{
  std::vector<double> vec1 = {1, 0, 0, 0, 1, 0, 0, 0, 1};
  std::vector<double> vec2 = {2, 0, 0, 0, 2, 0, 0, 0, 2};
  std::vector<double> vec3 = {3, 0, 0, 0, 3, 0, 0, 0, 3};
  std::vector<double> vec4 = {0, 0, 0, 0, 0, 0, 0, 0, 0};
  Matrix a{vec1, 3, 3};  
  Matrix b{vec2, 3, 3};  
  Matrix c{vec3, 3, 3}; 
  Matrix d{vec4, 3, 3};  
  CHECK(a==a);
  CHECK(b==b);
  CHECK(c==c);
  CHECK(d==d);
  // CHECK_THROWS(a>b);
  // CHECK_THROWS(a>c);
  // CHECK_THROWS(c<b);
  // CHECK_THROWS(d>a);
  // CHECK_THROWS(d>c);
  // CHECK_THROWS(d>b);


}

TEST_CASE("Bed matrix building")
{
  std::vector<double> vec1 = {1, 0, 0, 0, 1, 0, 0, 0, 1};
  std::vector<double> vec2 = {2, 0, 0, 0, 2, 0, 0, 0, 2};
  std::vector<double> vec3 = {3, 0, 0, 0, 3, 0, 0, 0, 3};
  std::vector<double> vec4 = {0, 0, 0, 0, 0, 0, 0, 0, 0};
 
   
  
  CHECK_THROWS( Matrix a(vec1, 2, 3));
  CHECK_THROWS( Matrix b(vec1, 3, 4));
  CHECK_THROWS(Matrix c(vec1, 1, 3));
  CHECK_THROWS(Matrix d(vec1, 3, 7));
  CHECK_THROWS(Matrix e(vec1, 1, 9));

  CHECK_THROWS( Matrix a(vec2, 2, 3));
  CHECK_THROWS( Matrix b(vec2, 3, 4));
  CHECK_THROWS(Matrix c(vec2, 1, 3));
  CHECK_THROWS(Matrix d(vec2, 3, 7));
  CHECK_THROWS(Matrix e(vec2, 1, 9));

  CHECK_THROWS( Matrix a(vec3, 2, 3));
  CHECK_THROWS( Matrix b(vec3, 3, 4));
  CHECK_THROWS(Matrix c(vec3, 1, 3));
  CHECK_THROWS(Matrix d(vec3, 3, 7));
  CHECK_THROWS(Matrix e(vec3, 1, 9));

}

TEST_CASE(" somting worng")
{
  
	
 
 
  srand(time(0));  // Initialize random number generator.
 
  // cout<<"Random numbers generated between 1 and 10:"<<endl;
  // for(int i=0;i<10;i++)
  // {
  //   std::vector<double> vec;
  //   for(unsigned int j=0 ; j<10 ; j++)
  //   {

  //     vec.push_back((rand() % 10) + 1);
  //   }
  //   CHECK_NOTHROW(Matrix e(vec, 5, 9));



  // }
}