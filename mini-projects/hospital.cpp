#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;




class Patient{
public:
string name;
int age;
string disease;
string doctorName;
Patient(string name,int age,string disease){
    this->name=name;
    this->age=age;
    this->disease=disease;
}
void assignDoctor(string docName){
    this->doctorName=docName;
}
void showPatientInfo(){
    cout<<"Patient Name : "<<name<<" | Age : "<<age<<" | Disease : "<<disease<<" | Doctor : "<<doctorName<<endl;
}
};
class Doctor{
public:
string name;
string specialization;
vector<Patient*>assignedPatient;
Doctor(string name,string specialization){
    this->name=name;
    this->specialization=specialization;
}
void assignPatient(Patient*p){
    assignedPatient.push_back(p);
    p->assignDoctor(name);
}
void dischargePatient(int idx){   
    if(idx>=0 && idx<assignedPatient.size()){
        cout<<assignedPatient[idx]->name<<" discharged from hospital"<<endl;
        assignedPatient.erase(assignedPatient.begin()+idx);
        
        return;
    }
    else{
        return;
    }
    
}
int patientCount(){
    int count=0;
    for(auto &num:assignedPatient){
        count++;
    }
    return count;
}
void showInfo(){
    cout<<"Name : "<<name<<" | Specialization : "<<specialization<<" | No. of patients assigned : "<<patientCount()<<endl;
}
void showAllPatient(){
    for(auto&num:assignedPatient){
        cout<<"Name : "<<num->name<<endl;
    }
}
};

class Hospital{
public:
vector<Doctor*>docList;
vector<Patient*>patList;
void newPatient(string name,int age,string disease){
    patList.push_back(new Patient(name,age,disease));
}
void newDoctor(string name,string specialization){
    docList.push_back(new Doctor(name,specialization));
}
void assignPatientToDoctor(Patient *p,Doctor* d){
    d->assignPatient(p);
}
void searchPatient(string name){
    for(auto &p:patList){
        if(p->name==name){
            p->showPatientInfo();
            return;
        }
    }
    cout<<name<<" is not admitted in hospital"<<endl;
    return;
}
void displayAllDoctor(){
    for(auto&num:docList){
        num->showInfo();
    }
    cout<<endl;
    return;
}
void displayAllPatient(Doctor*d){
    d->showAllPatient();
}
~Hospital(){
    for(Doctor* d : docList)delete d;
    for(Patient* p:patList)delete p;
}
};


int main() {
    Hospital hospital;

    // 1. Setup Doctor and Patient profiles
    hospital.newDoctor("Dr. House", "Diagnostics");
    hospital.newPatient("John Smith", 34, "Flu");

    // 2. Assign Patient (index 0 of both arrays)
    hospital.assignPatientToDoctor(hospital.patList[0], hospital.docList[0]);

    // 3. Show System Status
    cout << "--- Hospital Doctors ---" << endl;
    hospital.displayAllDoctor();

    cout << "--- Patients under Dr. House ---" << endl;
    hospital.displayAllPatient(hospital.docList[0]);

    // 4. Test Search
    cout << "\n--- Searching Database ---" << endl;
    hospital.searchPatient("John Smith");

    // 5. Test Discharge
    cout << "\n--- Testing Discharge ---" << endl;
    hospital.docList[0]->dischargePatient(0);

    return 0;
}
