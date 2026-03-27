# C++ Modern Object-Oriented Bootcamp

This project is a comprehensive training program designed to master modern C++ programming and object-oriented concepts. Divided into six progressive modules, each module builds upon the previous one, focusing on different skills and principles essential for robust software development.

## Table of Contents

- [Module 00 – Encapsulation](#module-00--encapsulation)
- [Module 01 – Relationships](#module-01--relationships)
- [Module 02 – UML Graphs](#module-02--uml-graphs)
- [Module 03 – SOLID Principles](#module-03--solid-principles)
- [Module 04 – Design Patterns](#module-04--design-patterns)
- [Module 05 – Railway Network Simulation](#module-05--railway-network-simulation)

## Module 00 – Encapsulation

This foundational module introduces the concept of **encapsulation**, a cornerstone of object-oriented programming.

### Key Concepts:
- **Data Hiding**: Keep internal data private to protect the object's state.
- **Access Control**: Use public methods to control how data is accessed and modified.
- **Benefits**: Ensures data integrity, reduces coupling, and improves maintainability.

By mastering encapsulation, you'll learn to create robust classes that hide complexity and expose only necessary interfaces.

## Module 01 – Relationships

Explore the various ways objects can interact and relate to each other in object-oriented design.

### Types of Relationships:
- **Composition**: Objects are integral parts of another object (e.g., a car has an engine).
- **Aggregation**: Objects are linked but can exist independently (e.g., a university has students).
- **Inheritance**: One class derives from another, inheriting properties and behaviors.
- **Association**: Objects communicate and collaborate (e.g., a teacher teaches students).

Understanding these relationships helps in modeling real-world systems and organizing code effectively.

## Module 02 – UML Graphs

Dive into visual representation of software architecture using Unified Modeling Language (UML).

### Objectives:
- Create UML class diagrams to illustrate relationships between classes.
- Utilize tools like **Doxygen** or **PlantUML** to generate visual diagrams.
- Generate PNG images that clearly show class structures and connections.

This module bridges the gap between design and implementation, allowing you to plan your code architecture before writing a single line.

## Module 03 – SOLID Principles

Learn the five fundamental principles of object-oriented design that promote maintainable and extensible code.

### The SOLID Principles:
1. **S - Single Responsibility Principle**: A class should have only one reason to change.
2. **O - Open/Closed Principle**: Software entities should be open for extension but closed for modification.
3. **L - Liskov Substitution Principle**: Subtypes must be substitutable for their base types.
4. **I - Interface Segregation Principle**: Clients should not be forced to depend on interfaces they don't use.
5. **D - Dependency Inversion Principle**: Depend on abstractions, not concretions.

### Practice:
Apply these principles through targeted exercises to create flexible, modular code.

## Module 04 – Design Patterns

Implement proven solutions to common software design problems using design patterns.

### Patterns Covered:
- **Singleton**: Ensure a class has only one instance and provide global access.
- **Mediator**: Define an object that encapsulates how a set of objects interact.
- **Observer**: Define a one-to-many dependency between objects.
- **Facade**: Provide a unified interface to a set of interfaces in a subsystem.

### Application:
Build a comprehensive school management system incorporating forms, roles, and events to efficiently manage students, professors, and administrative processes.

## Module 05 – Railway Network Simulation

Culminate your learning with a complex simulation project that integrates all previous concepts.

### Features:
- **Network Modeling**: Stations connected via various segments.
- **Singleton Registry**: Centralized storage for trains, stations, segments, and travelers.
- **Train Dynamics**: Realistic acceleration, braking, and movement between stations.
- **Pathfinding**: Algorithm to determine optimal routes.
- **Mediator Pattern**: Manage the entire railway system.
- **Observer Pattern**: Handle random events during simulation.
- **Performance Analysis**: Calculate average travel times for travelers.

### Technical Approach:
- Adhere to **SOLID** principles, **KISS** (Keep It Simple, Stupid), and **DRY** (Don't Repeat Yourself).
- Create detailed UML diagrams (class and sequence) using PlantUML to document structure and workflow.

---

This README provides a structured overview of the progressive learning path, from basic OOP concepts to advanced design patterns and real-world simulation. Each module builds essential skills for modern C++ development.