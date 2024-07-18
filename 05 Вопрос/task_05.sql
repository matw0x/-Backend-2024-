CREATE TABLE Departament (
	ID SERIAL PRIMARY KEY,
	SALARY VARCHAR(20) NOT NULL
);

CREATE TABLE Users (
	ID SERIAL PRIMARY KEY,
	SURNAME VARCHAR(25) NOT NULL,
	DEPARTAMENT_ID INT REFERENCES Departament(ID),
	SALARY INT NOT NULL
);

INSERT INTO Departament (SALARY)
VALUES
('Backend'),
('DevOps'),
('Android'),
('iOS');

INSERT INTO Users (SURNAME, DEPARTAMENT_ID, SALARY)
VALUES
('Алексеев', 3, 50000),
('Петрухин', 3, 60000),
('Есенин', 2, 70000),
('Маяковский', 1, 80000),
('Нортон', 4, 90000),
('Антропов', 1, 100000),
('Андреев', 4, 110000),
('Силантьев', 1, 120000);