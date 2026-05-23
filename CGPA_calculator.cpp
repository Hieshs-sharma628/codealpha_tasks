#include<iostream>
using namespace std;
class cgpa{
    int total_credits;
    float total_grade_points;
public:
    void calculateCGPA(){
        int n;
        cout << "Enter the number of subjects: ";
        cin >> n;
        for(int i = 0; i < n; i++){
            int credits;
            float grade_point;
            cout << "Enter credits for subject " << i+1 << ": ";
            cin >> credits;
            cout << "Enter grade point for subject " << i+1 << ": ";
            cin >> grade_point;
            total_credits += credits;
            total_grade_points += (credits * grade_point);
        }
        float cgpa = total_grade_points / total_credits;
        cout << "Your CGPA is: " << cgpa << endl;
    }
    cgpa(){ 
        total_credits = 0;
        total_grade_points = 0.0;
    }
};
int main(){
 cgpa student1;
 student1.calculateCGPA();
 return 0;
}