// float Q_rsqrt( float number )
// {
// 	long i;
// 	float x2, y;
// 	const float threehalfs = 1.5F;

// 	x2 = number * 0.5F;
// 	y  = number;
// 	i  = * ( long * ) &y;                       // evil floating point bit level hacking
// 	i  = 0x5f3759df - ( i >> 1 );               // what the fuck? 
// 	y  = * ( float * ) &i;
// 	y  = y * ( threehalfs - ( x2 * y * y ) );   // 1st iteration
// //	y  = y * ( threehalfs - ( x2 * y * y ) );   // 2nd iteration, this can be removed

// 	return y;
// }

// int main(){
// 	Q_rsqrt
// }

#include <iostream>
#include <string>

float fastInvSqrt(float x) {
  int i = *reinterpret_cast<int*>(&x);
  i = 0x5f3759df - (i >> 1);
  float y = *reinterpret_cast<float*>(&i);
  return y * (1.5F - 0.5F * x * y * y);
}

int main() {
  std::string line;
  while (std::getline(std::cin, line)) {
    try {
      std::cout << fastInvSqrt(std::stof(line, NULL)) << std::endl;
    } catch (...) {}
  }
  return 0;
}