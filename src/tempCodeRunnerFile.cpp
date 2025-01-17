void doctor::addPerson()
{
   if (hospital::doctorsList.size() == hospital::doctorsLimit)
        {
            cout << "\n\nDoctors limit reached, can't add more!"<<endl<<endl;
            return;
        }
        // 18 and 65 are the age limits for registration of a new doctor;
        person::addPerson(18, 65);
        //if ((age < 18) || (age > 65))
           // return;
        cout << "\nEnter the type of the doctor:"<<endl;
        getline(cin >> ws, type);
        if (hospital::doctorsList.rbegin() != hospital::doctorsList.rend())
            id = ((hospital::doctorsList.rbegin())->first) + 1;
        else
            id = 1;
        hospital::doctorsList[id] = *this;

        // creating a fstream object to read/write from/to files;
        fstream f;
        // creating a record in doctors.dat;
        f.open("doctors.dat", ios::binary|ios::app);
        f.write(reinterpret_cast<char*>(this),sizeof(doctor));
        f.close();

         cout <<endl<< "Dr. "<< firstName << " " << lastName << " registered successfully!"<<endl << "Their ID is: " << this->id << endl;
    
}