#include <iostream>
#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <cstdlib>
#include <fstream>
#include <string>
#include <ctype.h>
#include <time.h>
using namespace std;
//---------------------------------Global variables ------------------------------------
int count_candidate =0;
int count_voter=0;
int candidate_code;
int i=0;
int j=0;

//-----------------------------ALL CLASSES and objects-------------------------------------------
class person
{
protected:
char name[20];
int id;
int age;
public:
int get_id()
{
        return id;
}
};

class candidate : public person
{
char partyname[20];
char area[20];
int votes;
public:
candidate()
{
        votes=0;
}
void add_candidate_details();
void modify_candidate_details();
void display_candidate();
void delete_candidate();
int increaseVotes();
void display_winner();
} c[200];


class voter : public person
{

char voter_address[20];
int voter_status;
int password;
public:
voter()
{
        voter_status=0; //status= 0 if voter has not voted. Staus=1 if voter has already voted.
}
int get_password();
void add_voter_details();
void modify_voter_details();
void display_voter();
int validate_voter();
int get_voter_status();
void voted();
} v[200];

//-----------------------------------------------------------------------------------

//Function for adding candidate details
void candidate::add_candidate_details()
{
candidate_details:
        try{
                system("clear");
                cout<<"\n\t--------------------------------------------------------------\n";
                cout<<endl<<endl;
                cout<<"\tEnter candidate name:";
                cin>>name;
                cout<<endl<<endl;
                cout<<"\tEnter candidate id:";
                cin>>id;
                cout<<endl<<endl;
                cout<<"\tEnter party name:";
                cin>>partyname;
                cout<<endl<<endl;
                cout<<"\tEnter area:";
                cin>>area;
                cout<<endl<<endl;
                for(int i=0; i<20; i++)
                {
                        if(isdigit(name[i]))
                        {
                                throw name[20];
                        }
                        if(isdigit(partyname[i]))
                        {
                                throw partyname[20];
                        }
                        if(isdigit(area[i]))
                        {
                                throw area[20];
                        }
                }

                cout<<"\n\t--------------------------------------------------------------\n";
                cout<<"\n\tCandidate details successfully added\n";

                cout<<"\tPress Enter to continue\n";
                cin.ignore().get();
        }

        catch (int e)
        {
                cout<<"\n\tPlease Enter Correct Details.Invalid ID\n\t";
                cin.ignore().get();
                goto candidate_details;
        }
        catch (char j)
        {
                cout<<"\n\tPlease Enter Correct Details: \n\t";
                cin.ignore().get();
                goto candidate_details;
        }

}

// function for modifying candidate details
void candidate::modify_candidate_details()
{
        int ch3;
        system("clear");
        cout<<"\n\t--------------------------------------------------------------\n";
        cout<<"\n\t\t\t Current Candidate details"<<endl;
        cout<<"\n\t--------------------------------------------------------------\n";
        cout<<endl<<endl;
        display_candidate();
        cout<<"\n\t-------------------------------------------------------------\n";
        cout<<"\t\tSelect which field needs to be modified"<<endl<<endl;
        cout<<"\t1.Candidate Name\n\n\t2.Candidate id\n\n\t3.Party Name\n\n\t4.Area"<<endl;
        cout<<"\n\t--------------------------------------------------------------\n";
pp:
        cout<<"\tEnter Option:\t";
        cin>>ch3;
        if(ch3==1)
        {
                cout<<"\tEnter Candidate Name:\t";
                cin>>name;
                cout<<endl;
        }
        if(ch3==2)
        {
                cout<<"\tEnter Candidate id:\t";
                cin>>id;
                cout<<endl;
        }
        if(ch3==3)
        {
                cout<<"\tEnter Party Name:\t";
                cin>>partyname;
                cout<<endl;
        }
        if(ch3==4)
        {
                cout<<"\tEnter Area:\t";
                cin>>area;
                cout<<endl;
        }
        if(ch3>4||ch3<0)
        {
                goto pp;
        }
        cout<<"\n\tCandidate details successfully modfied\n";
}

//function for displaying candidate details
void candidate::display_candidate()
{
        cout<<"\t Candidate Name:   "<<name;
        cout<<endl;
        cout<<"\t Candidate id:   "<<id;
        cout<<endl;
        cout<<"\t Party Name:   "<<partyname;
        cout<<endl;
        cout<<"\t Area:   "<<area;
        cout<<endl<<endl<<endl;
}

//function for adding voter details
void voter::add_voter_details()
{
voter_details:
        try
        {
                system("clear");
                cout<<"\n\t--------------------------------------------------------------\n";
                cout<<endl<<endl;
                cout<<"\tEnter voter name:";
                cin>>name;
                cout<<endl<<endl;
                cout<<"\tEnter voter id:";
                cin>>id;
                cout<<endl<<endl;
                cout<<"\tEnter area of the voter:";
                cin>>voter_address;
                cout<<endl<<endl;
                cout<<"\tEnter the age of the voter:";
                cin>>age;
                cout<<endl<<endl;
                cout<<"\n\t--------------------------------------------------------------\n";

                for(int i=0; i<20; i++)
                {
                        if(isdigit(name[i]))
                        {
                                throw name[20];
                        }
                        if(isdigit(voter_address[i]))
                        {
                                throw voter_address[20];
                        }
                }
        }

        catch (char f)
        {
                cout<<"\n\tPlease Enter Correct Details.Invalid ID\n\t";
                cin.ignore().get();
                goto voter_details;
        }

        catch (int e)
        {
                cout<<"Please Enter Correct Details";
                cin.ignore().get();
                goto voter_details;
        }
        cout<<"\n\tVoter details successfully added\n";
        srand(time(0));
        password= rand()%1000;
        cout<<"\tYour password for voting is:"<<password;
        cout<<"\n";
        cout<<"\tPress Enter to continue\n";
        cin.ignore().get();
}

// function for modifying voter details
void voter::modify_voter_details()
{
        int ch3;
        system("clear");
        cout<<"\n\t--------------------------------------------------------------\n";
        cout<<"\n\t\t\t Current Voter details"<<endl;
        cout<<"\n\t--------------------------------------------------------------\n";
        cout<<endl<<endl;
        display_voter();
        cout<<"\n\t-------------------------------------------------------------\n";
        cout<<"\t\tSelect which field needs to be modified"<<endl<<endl;
        cout<<"\t1Voter Name\n\n\t2.Voter ID\n\n\t3.Voter Area\n\n\t4.Voter Age"<<endl;
        cout<<"\n\t--------------------------------------------------------------\n";
pp:
        cout<<"\tEnter Option:\t";
        cin>>ch3;
        if(ch3==1)
        {
                cout<<"\tEnter Voter Name:\t";
                cin>>name;
                cout<<endl;
        }
        if(ch3==2)
        {
                cout<<"\tEnter Voter ID:\t";
                cin>>id;
                cout<<endl;
        }
        if(ch3==3)
        {
                cout<<"\tEnter Voter Area:\t";
                cin>>voter_address;
                cout<<endl;
        }
        if(ch3==4)
        {
                cout<<"\tEnter Voter Age:\t";
                cin>>age;
                cout<<endl;
        }
        if(ch3>4||ch3<0)
        {
                goto pp;
        }
        cout<<"\n\tVoter details successfully modfied\n";
}

//function for displaying voter details
void voter::display_voter()
{
        cout<<"\t Voter Name:\t"<<name;
        cout<<endl;
        cout<<"\t Voter ID:\t"<<id;
        cout<<endl;
        cout<<"\t Voter Area:\t"<<voter_address;
        cout<<endl;
        cout<<"\t Voter Age:\t"<<age;
        cout<<endl<<endl<<endl;
}

//function for checking if voter is valid
int voter::validate_voter()
{
        if(this->age < 18)
                return 0;
        else
                return 1;
}

int voter::get_voter_status(){
        return voter_status;
}

int voter:: get_password()
{
        return password;
}

void voter::voted(){
        this->voter_status = 1;
}

int candidate::increaseVotes()
{
        if(candidate_code==id)
        {
                votes++;
                return votes;
        }
}

void candidate::display_winner()
{
        int largest;
        candidate winner;
        winner =c[0];
        for(i=0; i<count_candidate; i++)
        {
                if(c[i+1].votes>c[i].votes)
                {
                        winner=c[i+1];
                }
        }
        largest = winner.votes;
        winner.display_candidate();
        cout<<"\tThe winner is: ";
        cout<<winner.name;
        cout<<" with "<<largest<<" votes.\n\n";
}


void delete_voter(int id){
        int k;
        for(k = 0; k< count_voter; ++k ) {
                if(v[k].get_id() == id) {
                        break;
                }
        }

        if(k == count_voter) {
                cout<<"\tVoter not found\n";
                cin.ignore().get();
                return;
        }

        for(int l = k; l< count_voter; ++l) {
                v[l] = v[l+1];
        }
        cout<<"\tDeleted";
        cin.ignore().get();
        count_voter--;
}

//-----------------------------------------------------------------------------------

void init_voter()
{
        // open the file... read the contents of the file and assign the appropriate variables
        ifstream f1;
        f1.open("voter.txt");
        if(f1.is_open())
        {
                while(f1)
                {
                        f1.read((char*) &v[count_voter], sizeof(class voter));
                        count_voter++;
                        if(f1.eof())
                                break;
                }
                count_voter=count_voter-1;
                f1.close();
        }
        else
        {
                system("clear");
                cout<<"\tVoter DataBase Doesn't Exist\n\tInitialising new records and starting\n";
                cin.ignore().get();
                return;
        }
}

void init_candidate()
{
        // open the file... read the contents of the file and assign the appropriate variables
        ifstream f2;
        f2.open("candidate.txt");
        if(f2.is_open())
        {
                while(f2)
                {
                        f2.read((char*) &c[count_candidate], sizeof(class candidate));
                        count_candidate++;
                        if(f2.eof())
                                break;
                }
                count_candidate=count_candidate-1;
                f2.close();
        }
        else
        {
                system("clear");
                cout<<"\tCandidate DataBase Doesn't Exist\n\tInitialising new records and starting\n";
                cin.ignore().get();
                return;
        }
}

void write_candidate_data(){
        ofstream file_obj;
        file_obj.open("candidate.txt");
        for(int k=0; k<count_candidate; k++)
        {
                file_obj.write((char*)&c[k], sizeof(class candidate));
        }

        file_obj.close();
}

void write_voter_data()
{
        ofstream file_obj;
        file_obj.open("voter.txt");
        for(int k=0; k<count_voter; k++)
        {
                file_obj.write((char*)&v[k], sizeof(class voter));
        }
        file_obj.close();
}



//----------------MAIN FUNCTION---------------------------------------------------------
int main()
{
        init_voter();
        init_candidate();
        system("clear");
        int ch1,ch3,ch4;

page1:
        system("clear");
        cout<<"\t------------------------------------------------"<<endl<<endl;
        cout<<"\t\t\tMAIN MENU"<<endl<<endl;
        cout<<"\t------------------------------------------------"<<endl;
        cout<<endl<<endl<<endl;
        cout<<"\t1.Candidate DATABASE\n"<<endl;
        cout<<"\t2.Voter DATABASE\n"<<endl;
        cout<<"\t3.Casting vote\n"<<endl;
        cout<<"\t4.Exit \n"<<endl;
        cout<<endl<<endl;
        cout<<"\t---------------------------------------------------";
        cout<<endl<<endl;
        cout<<"\n\tEnter choice:";
        cin>>ch1;
        cout<<endl<<endl;
        cout<<"\t---------------------------------------------------\n";
        switch(ch1)
        {
        case 1:
                char ch2;

page2:
                system("clear");
                cout<<endl<<endl<<endl;
                cout<<"\t--------------------------------------------------"<<endl<<endl;
                cout<<"\t\t\tCANDIDATE DATABASE"<<endl<<endl;
                cout<<"\t--------------------------------------------------"<<endl;
                cout<<endl<<endl<<endl;
                cout<<"\t1.Add a candidate"<<endl<<endl;
                cout<<"\t2.Modify details of a candidate"<<endl<<endl;
                cout<<"\t3.Display the details of the candidate"<<endl<<endl;
                cout<<"\t4.Back to main menu"<<endl<<endl;
                cout<<"\t---------------------------------------------------";
                cout<<endl<<endl;
                cout<<"\t\n\tEnter choice:";
                cin>>ch2;
                cout<<endl<<endl;
                cout<<"\t---------------------------------------------------\n";

                if(ch2=='1')
                {
                        c[i].add_candidate_details();
                        i++;
                        count_candidate++;
                        write_candidate_data();
                        goto page2;
                }
                else if(ch2=='2')
                {
                        c[i-1].modify_candidate_details();
                        goto page2;
                }
                else if(ch2=='3')
                {
                        system("clear");
                        cout<<"\n\t--------------------------------------------------------------\n";
                        cout<<"\n\t\t\t Candidate List\n";
                        cout<<"\n\t--------------------------------------------------------------\n";
                        i=0;
                        while(i<count_candidate)
                        {
                                c[i].display_candidate();
                                i++;
                        }
                        cout<<"\tPress 'y' or 'Y' to continue\n";
                        char a;
                        cin>>a;
                        while(1)
                        {
                                if(a==27)
                                {
                                        exit(-1);
                                }
                                if(a=='y'|| a=='Y')
                                {
                                        break;
                                }
                        }
                        goto page2;
                }

                else if(ch2=='4')
                {
                        system("clear");
                        goto page1;
                }
                else{
                        cout<<"Invalid Option. Press Enter to continue\n";
                        cin.ignore().get();
                        goto page2;
                }
                break;
                //----------------------------------------------------------------------------------
                {
                case 2:
                        char ch3;

page3:
                        system("clear");
                        cout<<endl<<endl<<endl;
                        cout<<"\t--------------------------------------------------"<<endl<<endl;
                        cout<<"\t\t\tVOTER DATABASE"<<endl<<endl;
                        cout<<"\t--------------------------------------------------"<<endl;
                        cout<<endl<<endl<<endl;
                        cout<<"\t1.Add a voter"<<endl<<endl;
                        cout<<"\t2.Modify details of a voter"<<endl<<endl;
                        cout<<"\t3.Delete a voter"<<endl<<endl;
                        cout<<"\t4.Display the details of the voter"<<endl<<endl;
                        cout<<"\t5.Back to main menu"<<endl<<endl;
                        cout<<"\t---------------------------------------------------";
                        cout<<endl<<endl;
                        cout<<"\t\n\tEnter choice:";
                        cin>>ch3;
                        cout<<endl<<endl;
                        cout<<"\t---------------------------------------------------\n";
                        if(ch3=='1')
                        {
                                v[j].add_voter_details();
                                j++;
                                count_voter++;
                                write_voter_data();
                                goto page3;
                        }

                        else if(ch3=='2')
                        {
                                v[j-1].modify_voter_details();
                                goto page3;
                        }

                        else if(ch3 == '3') {
                                cout<<"\n\tEnter the voter ID";
                                int id;
                                cin>>id;
                                delete_voter(id);
                                goto page3;
                        }
                        else if(ch3=='4')
                        {
                                system("clear");
                                cout<<"\n\t--------------------------------------------------------------\n";

                                cout<<"\n\t\t\t Voter List\n";
                                cout<<"\n\t--------------------------------------------------------------\n";
                                for(j=0; j<count_voter; j++)
                                {
                                        v[j].display_voter();
                                }
                                cout<<"\tPress 'y' or 'Y' to continue\n";
                                char b;
                                cin>>b;
                                while(1)
                                {
                                        if(b==27)
                                        {
                                                exit(-1);
                                        }
                                        if(b=='y'|| b=='Y')
                                        {
                                                break;
                                        }
                                }
                                goto page3;
                        }
                        else if(ch3=='5')
                        {
                                system("clear");
                                goto page1;
                        }
                        else{
                                cout<<"Invalid Option. Press Enter to continue\n";
                                cin.ignore().get();
                                goto page3;
                        }
                }

                {
                case 3:
page4:
                        char ch4;
                        system("clear");
                        cout<<"\n\t--------------------------------------------------------------\n";
                        cout<<"\n \t\t\t Voting Booth";
                        cout<<"\n\t--------------------------------------------------------------\n";
                        cout<<"\n\t1.Display Voter List\n";
                        cout<<"\n\t2.Cast your vote\n";
                        cout<<"\n\t3.Display the Results\n";
                        cout<<"\n\t4.Back to Main Menu\n";
                        cout<<"\n\t--------------------------------------------------------------\n";
                        cout<<"\n\t Enter your choice:";
                        cin>>ch4;
                        cout<<"\n\t--------------------------------------------------------------\n";
                        if(ch4=='1')
                        {
                                system("clear");
                                cout<<"\t--------------------------------------------------------------\n";
                                cout<<"\n\t\t\t Voter List\n";
                                cout<<"\t--------------------------------------------------------------\n\n";
                                for(j=0; j<count_voter; j++)
                                {
                                        v[j].display_voter();
                                }
                                char b;
                                cout<<"\tPress 'y' or 'Y' to continue\n";
                                cin>>b;
                                if(b=='y'|| b=='Y')
                                {
                                        goto page4;
                                }
                        }
                        else if(ch4=='2')
                        {
                                int ch5;
                                system("clear");
                                cout<<"\t--------------------------------------------------------------\n";
                                cout<<"\n\t\t\t Voter List\n";
                                cout<<"\t--------------------------------------------------------------\n\n";
                                for(j=0; j<count_voter; j++)
                                {
                                        v[j].display_voter();
                                }
                                cout<<"\t--------------------------------------------------------------\n";
castVote:
                                cout<<"\n\t1)Cast your vote \n\t2)Back to voting booth\n\n ";
                                cout<<"\tEnter your choice:";
                                cout<<"\t";
                                cin>>ch5;
                                int VoterID;
                                int flag = 0;
                                int currentVoter;
                                if(ch5==1)
                                {
                                        int pw;
                                        cout<<"\n\n\tEnter Voter ID\t:";
                                        cin>>VoterID;

                                        {

                                                for(int k=0; k<count_voter; k++)
                                                {
                                                        if(v[k].get_id()== VoterID)
                                                        {
                                                                if(v[k].validate_voter())
                                                                {
                                                                        flag = 1;
                                                                        currentVoter = k;
                                                                        break;
                                                                }
                                                                else
                                                                {
                                                                        flag = 2;
                                                                }
                                                        }
                                                }
                                                if(flag == 0) {
                                                        cout<<"\tVoter with the given ID doesn't exist\n";
                                                        cin.ignore().get();
                                                        goto page4;
                                                }


                                                if(flag==2)
                                               {
                                                        cout<<"\tVoter is Not eligible to vote";
                                                        cin.ignore().get();
                                                        goto page4;
                                                }

password:
                                                cout<<"\n\tEnter your password\t:";
                                                cin>>pw;
                                                int a= v[currentVoter].get_password();
                                                if(pw!=a) {
                                                        cout<<"\n\tEnter Correct Password And Try Again\n";
                                                        cin.ignore().get();
                                                        goto  password;
                                                }



                                                if(flag == 1 )
                                                {
                                                        if(v[currentVoter].get_voter_status()== 1) {
                                                                cout<<"\tYou have alredy Voted. Going back to Voting Menu....\n";
                                                                cin.ignore().get();
                                                                goto page4;
                                                        }
                                                        cout<<"\n\t--------------------------------------------------------------------\n";
                                                        i=0;
                                                        cout<<"\n\t\t\t\tCandidate List\n\n";
                                                        cout<<"\t--------------------------------------------------------------------\n\n";
                                                        while(i<count_candidate)
                                                        {
                                                                c[i].display_candidate();
                                                                i++;
                                                        }
                                                        cout<<"\t--------------------------------------------------------------------\n";
                                                        cout<<"\n\tEnter candidate id of the candidate you want to vote for:\t";
                                                        cin>>candidate_code;
                                                        flag = 0;
                                                        for(int k=0; k<count_candidate; k++)
                                                        {
                                                                if(c[k].get_id() == candidate_code)
                                                                {
                                                                        c[k].increaseVotes();
                                                                        v[currentVoter].voted();
                                                                        flag = 1;
                                                                        break;
                                                                }
                                                        }
                                                        char b;
                                                        cout<<"\tPress 'y' or 'Y' to continue\n";
                                                        cin>>b;
                                                        if(b=='y'|| b=='Y')
                                                        {
                                                                goto page4;
                                                        }
                                                }


                                        }
                                }
                                else if(ch5==2)
                                {
                                        goto page4;
                                }
                                else
                                {
                                        cout<<"\tInvalid Option\n";
                                        cin.ignore().get();
                                        goto castVote;
                                }
                        }

                        else if(ch4=='3')
                        {
                                system("clear");
                                cout<<"\n\t-------------------------------------------\n";
                                cout<<"\n\t\t RESULTS\n";
                                cout<<"\n\t-------------------------------------------\n\n";

                                for(i=0; i<count_candidate; i++)
                                {
                                        c[i].display_winner();
                                }
                        }

                        else if(ch4=='4')
                        {
                                goto page1;
                        }

                        else
                        {
                                cout<<"Invalid Option. Press Enter to continue\n";
                                cin.ignore().get();
                                goto page4;
                        }
                        break;
                }
        case 4: exit(-1);
                break;
        default: cout<<"Invalid Option. Press Enter to continue\n";
                cin.ignore().get();
                goto page1;
        }

        return 0;
}
