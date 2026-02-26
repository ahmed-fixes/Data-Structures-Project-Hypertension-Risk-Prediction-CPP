# Data-Structures-Project-Hypertension-Risk-Prediction-CPP
C++ Object-Oriented Disease Prediction System using Logistic Regression, Doubly Linked List, and Binary Search Tree for Hypertension Risk Classification.

🏥 Disease Prediction System (C++ | OOP | DSA | Machine Learning)
This project is a C++ based Disease Prediction System that predicts Hypertension Risk using a manually implemented Logistic Regression model combined with core Data Structures concepts.
The system stores patients in a Doubly Linked List, processes them using a trained ML model, and organizes risk results using a Binary Search Tree (BST) sorted by probability.
🚀 Features
✅ Object-Oriented Design
✅ Custom Logistic Regression Implementation
✅ Feature Normalization (Scaling)
✅ Doubly Linked List for Patient Storage
✅ Binary Search Tree for Risk Ordering
✅ Risk Classification (High / Medium / Low)
✅ Probability Conversion to Percentage
✅ Manual Training with Gradient Descent

🧠 Concepts Implemented
🔹 Data Structures

Doubly Linked List (Patient Storage)
Binary Search Tree (Risk Sorting)
🔹 OOP Principles
Encapsulation
Abstraction
Inheritance
Polymorphism (Virtual Function in Logistic Regression)
🔹 Machine Learning
Logistic Regression
Sigmoid Function
Gradient Descent
Feature Scaling

📊 Risk Classification Logic
Probability	Risk Level
≥ 0.7	HIGH
≥ 0.4	MEDIUM
< 0.4	LOW
🏗 System Architecture

DiseasePredictionSystem
→ PatientDoublyLinkedList
→ HypertensionModel (inherits LogisticRegression)
→ DiseaseBST
→ TrainingManager

🛠 Technologies Used
C++
Object-Oriented Programming
Data Structures
Mathematical Modeling

📌 How It Works
User enters patient data
System trains logistic regression model
Model predicts hypertension probability
Patients are inserted into BST based on risk
System displays patients ordered by risk

🎯 Learning Outcomes
This project demonstrates:
Integration of DSA with Machine Learning
Manual implementation of ML algorithms in C++
Strong understanding of memory handling & pointers
Clean class-based system architecture
