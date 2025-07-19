class Solution {
public:
  void studentGrade(int marks) {
    if (marks < 35) {
      cout << "Fail";
    } else if (marks < 50) {
      cout << "Grade D";
    } else if (marks < 70) {
      cout << "Grade C";
    } else if (marks < 90) {
      cout << "Grade B";
    } else {
      cout << "Grade A";
    }
  }
};
