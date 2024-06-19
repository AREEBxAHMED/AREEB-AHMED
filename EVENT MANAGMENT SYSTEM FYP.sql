DROP DATABASE IF EXISTS EVENT_MANAGEMENT;
CREATE DATABASE EVENT_MANAGEMENT;
USE EVENT_MANAGEMENT;

CREATE TABLE Organizer (
    OrganizerID INT PRIMARY KEY,
    OrganizerName VARCHAR(100),
    OrganizerContact VARCHAR(50)
);

CREATE TABLE Venue (
    VenueID INT PRIMARY KEY,
    VenueName VARCHAR(100),
    VenueLocation VARCHAR(100),
    Capacity INT
);

CREATE TABLE Event (
    EventID INT PRIMARY KEY,
    EventName VARCHAR(100),
    EventType VARCHAR(50),
    EventDate DATE,
    EventDescription TEXT,
    VenueID INT,
    OrganizerID INT,
    FOREIGN KEY (VenueID) REFERENCES Venue(VenueID),
    FOREIGN KEY (OrganizerID) REFERENCES Organizer(OrganizerID)
);

CREATE TABLE Feedback (
    FeedbackID INT PRIMARY KEY,
    FeedbackContent TEXT,
    FeedbackRating INT,
    FeedbackDate DATE
);

CREATE TABLE Registration (
    RegistrationID INT PRIMARY KEY,
    RegistrationDate DATE,
    RegistrationStatus VARCHAR(20),
    EventID INT,
    AttendeeID INT,
    FOREIGN KEY (EventID) REFERENCES Event(EventID)
);

CREATE TABLE Attendee (
    AttendeeID INT PRIMARY KEY,
    AttendeeName VARCHAR(100),
    AttendeeContact VARCHAR(50),
    FeedbackID INT,
    RegistrationID INT,
    FOREIGN KEY (FeedbackID) REFERENCES Feedback(FeedbackID),
    FOREIGN KEY (RegistrationID) REFERENCES Registration(RegistrationID)
);

CREATE TABLE Expense (
    ExpenseID INT PRIMARY KEY,
    ExpenseType VARCHAR(50),
    ExpenseAmount DECIMAL(10, 2),
    ExpenseDate DATE,
    EventID INT,
    FOREIGN KEY (EventID) REFERENCES Event(EventID)
);

INSERT INTO Organizer (OrganizerID, OrganizerName, OrganizerContact) VALUES
(1, 'ALI AHMED', 'ali123@gmail.com'),
(2, 'ABDUL RAHEEM', 'abduraheem123@gmail.com'),
(3, 'SAMI KHAN', 'samikhan123@gmail.com'),
(4, 'AHSAN RAZA', 'ahsanraza123@gmail.com'),
(5, 'FARAH NAZ', 'farahnaz123@gmail.com');

INSERT INTO Venue (VenueID, VenueName, VenueLocation, Capacity) VALUES
(1, 'Convention Center', 'Islamabad', 1000),
(2, 'Outdoor Park', 'Rawalpindi', 5000),
(3, 'Roof Top', 'Jhang', 10000),
(4, 'Community Hall', 'Lahore', 3000),
(5, 'Beachside Arena', 'Karachi', 7000);

INSERT INTO Event (EventID, EventName, EventType, EventDate, EventDescription, VenueID, OrganizerID) VALUES
(1, 'Tech Conference', 'Conference', '2024-07-01', 'A conference on the latest in technology.', 1, 1),
(2, 'Music Festival', 'Festival', '2024-08-15', 'A festival featuring various artists and bands.', 2, 2),
(3, 'Education Seminar', 'Seminar', '2024-09-11', 'A seminar featuring various motivational speakers and brands.', 3, 3),
(4, 'Food Expo', 'Expo', '2024-10-05', 'An exposition showcasing various food and beverage companies.', 4, 4),
(5, 'Startup Pitch', 'Competition', '2024-11-20', 'A competition for startups to pitch their ideas.', 5, 5);

INSERT INTO Feedback (FeedbackID, FeedbackContent, FeedbackRating, FeedbackDate) VALUES
(1, 'Great event!', 5, '2024-07-02'),
(2, 'Loved the performances!', 4, '2024-08-16'),
(3, 'Average experience.', 3, '2024-09-12'),
(4, 'Excellent organization!', 5, '2024-10-06'),
(5, 'Could be better.', 2, '2024-11-21');

INSERT INTO Registration (RegistrationID, RegistrationDate, RegistrationStatus, EventID, AttendeeID) VALUES
(1, '2024-06-01', 'Confirmed', 1, 1),
(2, '2024-07-01', 'Pending', 2, 2),
(3, '2024-08-10', 'Confirmed', 3, 3),
(4, '2024-09-15', 'Cancelled', 4, 4),
(5, '2024-10-01', 'Confirmed', 5, 5);

INSERT INTO Attendee (AttendeeID, AttendeeName, AttendeeContact, FeedbackID, RegistrationID) VALUES
(1, 'AREEB AHMED', 'areeb123@gmail.com', 1, 1),
(2, 'ABDUL HADI', 'hadi123@gmail.com', 2, 2),
(3, 'ZASHAN TANVEER', 'zashan123@gmail.com', 3, 3),
(4, 'MOHSIN ALI', 'mohsinali123@gmail.com', 4, 4),
(5, 'MAHA KHAN', 'maha123@gmail.com', 5, 5);

INSERT INTO Expense (ExpenseID, ExpenseType, ExpenseAmount, ExpenseDate, EventID) VALUES
(1, 'Catering', 500.00, '2024-06-20', 1),
(2, 'Equipment', 2000.00, '2024-07-15', 2),
(3, 'Marketing', 1500.00, '2024-08-25', 3),
(4, 'Venue Rental', 10000.00, '2024-09-30', 4),
(5, 'Security', 3000.00, '2024-11-10', 5);

SELECT * FROM Organizer;
SELECT * FROM Venue;
SELECT * FROM Event;
SELECT * FROM Feedback;
SELECT * FROM Registration;
SELECT * FROM Attendee;
SELECT * FROM Expense;
