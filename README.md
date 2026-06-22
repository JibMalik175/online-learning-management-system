# 🎓 Online Learning Management System (LMS)

A console-based **Online Learning Management System** written in **C++**, built as an Object-Oriented Programming course project. It models a complete e-learning platform with three user roles — **Student**, **Instructor**, and **Admin** — each with their own menu and capabilities, plus courses, modules, assignments, assessments, certificates, and notifications.

> The project is a practical demonstration of the four pillars of OOP: **abstraction, inheritance, polymorphism, and encapsulation**.

---

## ✨ Features

### 👨‍🎓 Student
- Browse and enroll in available courses
- Submit assignments
- Track course progress
- View earned certifications
- Add and view a peer group

### 👨‍🏫 Instructor
- Create assignments for assigned courses
- Grade student submissions
- Monitor student progress (and flag low performers)
- Issue certifications
- View assigned courses

### 🛠️ Admin
- Add / remove courses
- Assign instructors to courses
- Generate reports
- Manage certificates (view / issue / revoke)
- Send system notifications to students and instructors

### Shared Modules
- **Modules** — course content broken into sections
- **Assessments** — take quizzes/exams and view scores
- **Certificates** — certificates of completion
- **Notifications** — send to individuals or broadcast

---

## 🧩 OOP Concepts Demonstrated

| Concept | How it's used |
|---------|---------------|
| **Abstraction** | `Person` is an abstract base class with pure virtual methods (`displayInfo`, `getRole`, `sendNotification`). |
| **Inheritance** | `Student`, `Instructor`, and `Admin` all derive from `Person`. |
| **Polymorphism** | Virtual functions are overridden per role and resolved at runtime. |
| **Encapsulation** | Class data is kept `private`/`protected` and accessed through methods. |

### Core Classes
`Person` (abstract) → `Student`, `Instructor`, `Admin` · `Course` · `Module` · `Assignment` · `Assessment` · `Certificate` · `Notification`

A UML class diagram is included: [`Class_Diagram.pdf`](Class_Diagram.pdf).

---

## 🛠️ Build & Run

### Option A — Visual Studio
Open **`OOP-Project.sln`**, then build and run (`Ctrl + F5`).

### Option B — Compile directly
```bash
g++ -std=c++17 -o lms "OOP-Project/OnlineLearningSystem.cpp"
./lms          # Windows: lms.exe
```

On launch you'll see the home page; log in as a Student, Instructor, or Admin to explore each role's menu.

---

## 📁 Project Structure

```
.
├── OOP-Project.sln                 # Visual Studio solution
├── Class_Diagram.pdf               # UML class diagram
├── OOP-Project/
│   ├── OnlineLearningSystem.cpp    # Full application source
│   ├── OOP-Project.vcxproj         # VS project file
│   └── OOP-Project.vcxproj.filters
└── README.md
```

---

## 👥 Authors

Object-Oriented Programming course project by **Jibran Malik** & **Agha Ahsan**
Roll numbers: `21i-1117`, `22i-2517`
