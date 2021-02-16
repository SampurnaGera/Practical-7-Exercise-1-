#include "Blood.cpp"
#include <vector>

class Patient
{
    protected:
        string name;
        std::vector<int> vectsys;
        std::vector<int> vectdias;
        std::vector<int> vectday;
        std::vector<int> vectmonth;
        std::vector<int> vectyear;
    public:
        Patient(string n)
            {
                name = n;
            }
            void addRecord(Blood blod)
            {

                vectsys.push_back(blod.sys);
                vectdias.push_back(blod.dias);
                vectday.push_back(blod.day);
                vectmonth.push_back(blod.month);
                vectyear.push_back(blod.year);
            }
        void printReport()
            {
                cout << " Patient: " << name << "\n";
                for (int i = 0;i<vectsys.size();i++)
                {
                    cout << "systolic : " << vectsys[i] << " dialostic : " << vectdias[i] << " date : "
                    << vectday[i] << "/" << vectmonth[i] << "/" << vectyear[i] << "\n";
                }
                // finding the max element and looking at the measurement

                int max_index;
                int max_value;
                int max_pressure_index;
                int max_pressure_value;
                bool flag;
                float average;
                max_index = 0;
                max_value = vectsys[0];
                max_pressure_index = 0;
                max_pressure_value = vectsys[0] + vectdias[0];
                average = 0;
                flag = false;
                for (int i = 0;i<vectsys.size();i++)
                {
                    // computing the maximum value
                    if (vectsys[i]>max_value)
                    {
                        max_value = vectsys[i];
                        max_index = i;
                    }
                    // checking if all measurement are high
                    if (vectsys[i]>140)
                    {
                        flag = true;
                    }
                    // computing the average dialostic pressure
                    average += vectdias[i];

                    // computing the maximal pressure records
                    if (vectsys[i] + vectdias[i]>max_pressure_value)
                    {
                        max_pressure_value = vectsys[i] + vectdias[i];
                        max_pressure_index = i;
                    }

                }
                cout << "The highest abnormal systolic blood pressures is : " << vectsys[max_index] << "\n"
                << " It's diastolic value is : " << vectdias[max_index] << "\n"<<" It's date of measurement is : "
                << vectday[max_index] << "/" << vectmonth[max_index] << "/" << vectyear[max_index] << "\n";

                // looking at measurements
                if (flag == false)
                {
                    cout << "No measurement was too high" << "\n";
                }
                

                average = average/vectdias.size();
                cout << "The average diastolic blood pressure is " << average << "\n";

                cout << "The max blood pressures has a systolic blood pressure of " << vectsys[max_pressure_index ]
                << " and it's diastolic value is " << vectdias[max_pressure_index ] << "\n";
            }
};