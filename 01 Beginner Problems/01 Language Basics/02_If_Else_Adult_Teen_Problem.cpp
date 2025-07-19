class Solution {
public:
  void isAdult(int age) {
    // Your code goes here
    if (age >= 18) {
      cout << "Adult" << '\n';
    } else if (age < 18) {
      cout << "Teen" << '\n';
    }
  }
};
