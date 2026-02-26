#include <iostream>
#include <cmath>
using namespace std;

// PATIENT 

class Patient
{
public:
    int id;
    int age;
    int sugar;
    int bp;
    float bmi;
    float hyperProb;

    Patient(int i = 0, int a = 0, float b = 0, int s = 0, int p = 0)
    {
        id = i;
        age = a;
        bmi = b;
        sugar = s;
        bp = p;
        hyperProb = 0;
    }
};

// DLL NODE 

struct DLLNode
{
    Patient data;
    DLLNode* prev;
    DLLNode* next;
};

// PATIENT DOUBLY LINKED LIST 

class PatientDoublyLinkedList
{
protected:
    DLLNode* head;
    DLLNode* tail;

public:
    PatientDoublyLinkedList() 
    {
        head = nullptr; tail = nullptr;
    }

    void insert(Patient p)
    {
        DLLNode* nn = new DLLNode;
        nn->data = p;
        nn->prev = nullptr;
        nn->next = nullptr;

        if (head == nullptr && tail == nullptr)
        {
            head = nn; tail = nn;
        }
        else
        {
            tail->next = nn;
            nn->prev = tail;
            tail = nn;
        }
    }

    DLLNode* getHead()
    {
        return head;
    }
};

// FEATURE SCALER 

class FeatureScaler
{
public:

    void normalize (Patient& p, float& a, float& b, float& s, float& bp)
    {
        a = p.age / 100.0f;
        b = p.bmi / 50.0f;
        s = p.sugar / 300.0f;
        bp = p.bp / 200.0f;
    }
};

//LOGISTIC REGRESSION 

class LogisticRegression
{
protected:

    float wAge, wBMI, wSugar, wBP, bias;
    FeatureScaler scaler;

    float sigmoid(float z) 
    {
        return 1.0f / (1.0f + exp(-z));
    }

public:
    LogisticRegression()
    {
        wAge = 0.1f;
        wBMI = 0.1f;
        wSugar = 0.1f;
        wBP = 0.1f;
        bias = 0;
    }

    virtual int label(Patient& p) 
    {
        return 0;
    }

    void train(Patient dataset[], int size, int epochs, float lr)
    {
        for (int i = 0; i < epochs; i++)
        {
            for (int j = 0; j < size; j++)
            {
                float a, b, s, bp;
                scaler.normalize(dataset[j], a, b, s, bp);

                float z =  (wAge * a)  +  (wBMI * b)  +  (wSugar * s)  +  (wBP * bp) + bias;

                float y_hat = sigmoid(z);
                int y = label(dataset[j]);
                float error = y_hat - y;

                wAge = wAge -  lr * error * a ;
                wBMI = wBMI -  lr * error * b ;
                wSugar = wSugar -  lr * error * s ;
                wBP = wBP -  lr * error * bp ;
                bias = bias -  lr * error ;

            }
        }
    }

    float predict(Patient& p)
    {
        float a, b, s, bp;
        scaler.normalize(p, a, b, s, bp);
        float z =  (wAge * a)  +  (wBMI * b)  +  (wSugar * s)  +  (wBP * bp)  + bias ;
        return sigmoid(z);
    }
};

// HYPERTENSION MODEL

class HypertensionModel : public LogisticRegression
{
public:
    int label(Patient& p)
    {
        if (p.bp >= 140)
        {
            return 1;
        }
        return 0;
    }
};

// BST NODE 

struct BSTNode
{
    Patient data;
    float prob;
    BSTNode* left;
    BSTNode* right;
};

class ProbabilityConverter
{
public:
    float converttoPercentage(float value)
    {
        return value * 100.0f;
    }
};

// RISK CLASSIFIER 

class RiskClassifier
{
public:
    static void classify(float p)
    {
        if (p >= 0.7)
        {
            cout << "HIGH";
        }
        else if (p >= 0.4)
        {
            cout << "MEDIUM";
        }
        else
        {
            cout << "LOW";
        }
    }
};

// DISEASE BST 

class DiseaseBST
{
protected:

    BSTNode* root;
    ProbabilityConverter converter;

    void INORDER(BSTNode* p)
    {
        if (p != nullptr)
        {
            INORDER(p->left);

            cout << "Patient ID: " << p->data.id << " | Risk Probability: " << converter.converttoPercentage(p->prob) << "%" << " | Risk Level: ";
            RiskClassifier::classify(p->prob);
            cout << endl;
            INORDER(p->right);
        }
    }

public:
    DiseaseBST()
    {
        root = nullptr;
    }

    void add(Patient p, float pr)
    {

        BSTNode* nn = new BSTNode;
        nn->data = p;
        nn->prob = pr;
        nn->left = nullptr;
        nn->right = nullptr;

        if (root == nullptr)
        {
            root = nn;
        }

        else
        {

            BSTNode* c = root;
            while (true)
            {
                if (pr > c->prob)
                {
                    if (c->left == nullptr) 
                    {
                        c->left = nn;
                        break;
                    }
                    c = c->left;
                }
                else
                {
                    if (c->right == nullptr)
                    {
                        c->right = nn;
                        break;
                    }
                    c = c->right;
                }
            }
        }
    }

    void display() 
    {
        INORDER(root);
    }
};

// TRAINING MANAGER 

class TrainingManager
{
public:
    void loadHypertensionData(Patient dataset[], int& size)
    {
        size = 4;
        dataset[0] = Patient(1, 60, 30, 180, 150);
        dataset[1] = Patient(2, 45, 25, 110, 120);
        dataset[2] = Patient(3, 50, 28, 150, 145);
        dataset[3] = Patient(4, 35, 22, 130, 135);
    }
};

// SYSTEM CONTROLLER 

class DiseasePredictionSystem
{
private:

    PatientDoublyLinkedList patients;
    HypertensionModel hyperModel;
    DiseaseBST hyperTree;
    TrainingManager trainer;

public:

    void addPatient(Patient p)
    {
        patients.insert(p);
    }

    void trainModel()
    {
        Patient hyperData[4];
        int size;
        trainer.loadHypertensionData(hyperData, size);
        hyperModel.train(hyperData, size, 2000, 0.1f);
    }

    void processPatients()
    {
        DLLNode * temp = patients.getHead();
        while (temp != nullptr)
        {
            temp->data.hyperProb = hyperModel.predict(temp->data);
            hyperTree.add(temp->data, temp->data.hyperProb);
            temp = temp->next;
        }
    }

    void displayResults()
    {
        cout << endl;
        cout <<" Hypertension Risk Order " << endl;
        hyperTree.display();
    }

};

// MAIN 

int main()
{
    DiseasePredictionSystem system;

    int n;
    cout << "Enter number of patients: ";
    cin >> n;

    for (int i = 0 ; i < n ; i++)
    {
        int id, age, sugar, bp;
        float bmi;
        cout << endl;
        cout << "Enter Patient ID : ";
        cin >> id;
        cout << "Enter Age: ";
        cin >> age;
        cout << "Enter BMI: ";
        cin >> bmi;
        cout << "Enter Sugar Level: ";
        cin >> sugar;
        cout << "Enter Blood Pressure: ";
        cin >> bp;  

        system.addPatient ( Patient (id, age, bmi, sugar, bp) );
    }

    system.trainModel();
    system.processPatients();
    system.displayResults();

    return 0;
}
