INSERT INTO Uczestnik VALUES (96116173214,1,'Mariusz','Pudzianowski','Mielno','Jana Pawła II','21','najsilniejszy');
INSERT INTO Uczestnik VALUES (97035113374,1,'Maciej','Lubacz','Zakroczym','Morelowa','7','qwerty123');
INSERT INTO Uczestnik VALUES (96110613374,0,'Adam','Małysz','Wisła','Akacjowa','3','bulkazbananem');
INSERT INTO Uczestnik VALUES (96102124374,0,'Łukasz','Seremet','Płock','Górna','2','qwerty');
INSERT INTO Uczestnik VALUES (96011353874,1,'Tomasz','Chmielewski','Trzaska','Okopowa','6','haslo123');
INSERT INTO Uczestnik VALUES (96105862136,0,'Karolina','Gąsienica','Sosnowiec','Poniatowskiego','1','polag');
INSERT INTO Uczestnik VALUES (96108765374,0,'Anna','Piotrowska','Słupno','Magiczna','98','Qwerty1234');
INSERT INTO Uczestnik VALUES (96101707674,1,'Michał','Podkański','Poznań','Pastelowa','12','haslooo1');
INSERT INTO Uczestnik VALUES (98100713109,0,'Maja','Świrta','Konin','Fabryczna','4','123456789');
INSERT INTO Uczestnik VALUES (98100700374,1,'Żaneta','Bigos','Starozreby','Młodzieżowa','37','HaZu000');

Select * From Uczestnik;

INSERT INTO Opiekun VALUES (81116173214,'Eugeniusz','Korek','Warsawa','Jana Pawła II','37');
INSERT INTO Opiekun VALUES (67035113374,'Marek','Smolarek','Łódz','Topolowa','7');
INSERT INTO Opiekun VALUES (91116131161,'Robert','Lewandowski','Gdańsk','Akacjowa','3');
INSERT INTO Opiekun VALUES (91232124374,'Łukasz','Smuda','Warszawa','Dolna','73');
INSERT INTO Opiekun VALUES (96811353874,'Adrian','Chmielnicki','Toruń','Okopowa','21');
INSERT INTO Opiekun VALUES (91857912136,'Jan','Kojdyło','Lublin','Pudzianowskiego','8');
INSERT INTO Opiekun VALUES (82132765374,'Adrianna','Łuszcz','Katowice','Wyszyńskiego','21');
INSERT INTO Opiekun VALUES (93101718674,'Michał','Wilczyński','Poznań','Akacjowa','2');
INSERT INTO Opiekun VALUES (90100716009,'Michalnia','Madczyńska','Poznań','Fabryczna','2');
INSERT INTO Opiekun VALUES (61100782374,'Piotr','Malesa','Piotrków','Zielona','57');

SELECT * FROM Opiekun;

INSERT INTO Lokalizacja VALUES (1,'Stadion Miejski','Warszawa','Batorego',4,1,25);
INSERT INTO Lokalizacja VALUES (2,'Pływalnia Foka','Warszawa','Inflancka',7,1,30);
INSERT INTO Lokalizacja VALUES (3,'Sala gimnastyczna','Warszawa','Waryńskiego',12,4,25);
INSERT INTO Lokalizacja VALUES (4,'Sala gimnastyczna','Warszawa','Waryńskiego',12,5,35);
INSERT INTO Lokalizacja VALUES (5,'Sala gimnastyczna','Warszawa','Waryńskiego',12,6,50);
INSERT INTO Lokalizacja VALUES (6,'Siłownia','Warszawa','Kulskiego',166,5,20);

SELECT * FROM Lokalizacja;

INSERT INTO Dyscyplina VALUES (1,'Piłka nożna');
INSERT INTO Dyscyplina VALUES (2,'Basen');
INSERT INTO Dyscyplina VALUES (3,'Siatkówka');
INSERT INTO Dyscyplina VALUES (4,'Pakowanie');
INSERT INTO Dyscyplina VALUES (5,'Koszykówka');
INSERT INTO Dyscyplina VALUES (6,'Piłka ręczna');
INSERT INTO Dyscyplina VALUES (7,'Aeorobik');
INSERT INTO Dyscyplina VALUES (8,'Taniec towarzyski');

SELECT * FROM Dyscyplina;

INSERT INTO Dzień_tygodnia VALUES (1, 'Poniedziałek');
INSERT INTO Dzień_tygodnia VALUES (2,'Wtorek');
INSERT INTO Dzień_tygodnia VALUES (3,'Środa');
INSERT INTO Dzień_tygodnia VALUES (4,'Czwartek');
INSERT INTO Dzień_tygodnia VALUES (5,'Piątek');
INSERT INTO Dzień_tygodnia VALUES (6,'Sobota');
INSERT INTO Dzień_tygodnia VALUES (7,'Niedziela');

SELECT * FROM Dzień_tygodnia;

INSERT INTO Gość VALUES (96110613374);
INSERT INTO Gość VALUES (96102124374);
INSERT INTO Gość VALUES (96105862136);
INSERT INTO Gość VALUES (96108765374);
INSERT INTO Gość VALUES (98100713109);

SELECT * FROM Gość;

INSERT INTO Student VALUES (96116173214,271263,'Mechatronika',2018);
INSERT INTO Student VALUES (97035113374,272137,'WIP',2017);
INSERT INTO Student VALUES (96011353874,279132,'MEL',2018);
INSERT INTO Student VALUES (96101707674,283214,'EiTi',2017);
INSERT INTO Student VALUES (98100700374,279195,'MiNI',2016);

SELECT * FROM Student;

#przyjęte założenie - forma = 0 oznacza zajęcia otwarte
INSERT INTO Zajęcia VALUES(1,1,'16:00','18:00',1,1,1);
INSERT INTO Zajęcia VALUES(2,0,'10:00','20:00',2,5,2);
INSERT INTO Zajęcia VALUES(3,1,'12:00','14:00',3,2,4);
INSERT INTO Zajęcia VALUES(4,1,'14:00','16:00',3,3,3);
INSERT INTO Zajęcia VALUES(5,0,'10:00','16:00',4,5,6);
INSERT INTO Zajęcia VALUES(6,0,'16:00','20:00',4,4,6);
INSERT INTO Zajęcia VALUES(7,1,'12:00','14:00',5,1,4);
INSERT INTO Zajęcia VALUES(8,1,'10:00','12:00',6,2,5);
INSERT INTO Zajęcia VALUES(9,1,'8:00','10:00',7,5,3);
INSERT INTO Zajęcia VALUES(10,1,'18:00','20:00',8,3,4);

SELECT * FROM Zajęcia;

#DELETE FROM Przeprowadzenie_zajęć WHERE Id_Zajęć = 1;
INSERT INTO Przeprowadzenie_zajęć VALUES (1,1,81116173214,'2018-10-16');
INSERT INTO Przeprowadzenie_zajęć VALUES (2,2,91116131161,'2017-10-20');
INSERT INTO Przeprowadzenie_zajęć VALUES (3,3,91232124374,'2018-10-17');
INSERT INTO Przeprowadzenie_zajęć VALUES (4,4,91857912136,'2016-10-19');
INSERT INTO Przeprowadzenie_zajęć VALUES (5,5,96811353874,'2018-10-20');
INSERT INTO Przeprowadzenie_zajęć VALUES (6,6,67035113374,'2018-10-19');
INSERT INTO Przeprowadzenie_zajęć VALUES (7,7,93101718674,'2018-10-16');
INSERT INTO Przeprowadzenie_zajęć VALUES (8,8,82132765374,'2017-10-17');
INSERT INTO Przeprowadzenie_zajęć VALUES (9,9,61100782374,'2018-10-20');
INSERT INTO Przeprowadzenie_zajęć VALUES (10,10,90100716009,'2018-10-18');

INSERT INTO Przeprowadzenie_zajęć VALUES (11,1,81116173214,'2018-10-23');
INSERT INTO Przeprowadzenie_zajęć VALUES (12,2,91116131161,'2017-10-27');
INSERT INTO Przeprowadzenie_zajęć VALUES (13,3,91232124374,'2018-10-24');
INSERT INTO Przeprowadzenie_zajęć VALUES (14,4,91857912136,'2016-10-26');
INSERT INTO Przeprowadzenie_zajęć VALUES (15,5,91857912136,'2018-10-27');
INSERT INTO Przeprowadzenie_zajęć VALUES (16,6,67035113374,'2018-10-26');
INSERT INTO Przeprowadzenie_zajęć VALUES (17,7,93101718674,'2018-10-23');
INSERT INTO Przeprowadzenie_zajęć VALUES (18,8,82132765374,'2017-10-24');
INSERT INTO Przeprowadzenie_zajęć VALUES (19,9,61100782374,'2018-10-27');
INSERT INTO Przeprowadzenie_zajęć VALUES (20,10,90100716009,'2018-10-25');

INSERT INTO Przeprowadzenie_zajęć VALUES (21,1,81116173214,'2018-10-30');
INSERT INTO Przeprowadzenie_zajęć VALUES (22,2,91116131161,'2017-11-03');
INSERT INTO Przeprowadzenie_zajęć VALUES (23,3,91232124374,'2018-10-31');
INSERT INTO Przeprowadzenie_zajęć VALUES (24,4,91857912136,'2016-11-02');
INSERT INTO Przeprowadzenie_zajęć VALUES (25,5,96811353874,'2018-11-03');
INSERT INTO Przeprowadzenie_zajęć VALUES (26,6,67035113374,'2018-11-02');
INSERT INTO Przeprowadzenie_zajęć VALUES (27,7,93101718674,'2018-10-30');
INSERT INTO Przeprowadzenie_zajęć VALUES (28,8,82132765374,'2017-10-31');
INSERT INTO Przeprowadzenie_zajęć VALUES (29,9,61100782374,'2018-11-03');
INSERT INTO Przeprowadzenie_zajęć VALUES (30,10,93101718674,'2018-11-01');

SELECT * FROM Przeprowadzenie_zajęć;

INSERT INTO Zapisy VALUES (1,96116173214,6,1,2018,3);
INSERT INTO Zapisy VALUES (2,97035113374,8,1,2017,3);
INSERT INTO Zapisy VALUES (3,96011353874,1,1,2018,3);
INSERT INTO Zapisy VALUES (4,96101707674,2,0,2017,1);
INSERT INTO Zapisy VALUES (5,98100700374,4,1,2016,3);

SELECT * FROM Zapisy;

INSERT INTO Uczestnictwo_w_zajęciach VALUES (1,96116173214,6,'18:00','20:00','2018-10-19',0,1);
INSERT INTO Uczestnictwo_w_zajęciach VALUES (2,97035113374,8,'10:00','12:00','2017-10-17',0,1);
INSERT INTO Uczestnictwo_w_zajęciach VALUES (3,96011353874,1,'16:00','18:00','2018-10-16',0,1);
INSERT INTO Uczestnictwo_w_zajęciach VALUES (4,96101707674,2,'16:00','17:00','2017-10-20',0,0);
INSERT INTO Uczestnictwo_w_zajęciach VALUES (5,98100700374,4,'14:00','16:00','2016-10-19',0,1);
INSERT INTO Uczestnictwo_w_zajęciach VALUES (6,96116173214,6,'16:00','19:00','2018-10-26',0,1);
INSERT INTO Uczestnictwo_w_zajęciach VALUES (7,97035113374,8,'10:00','12:00','2017-10-24',0,1);
INSERT INTO Uczestnictwo_w_zajęciach VALUES (8,96011353874,1,'16:00','18:00','2018-10-23',0,1);
INSERT INTO Uczestnictwo_w_zajęciach VALUES (9,96101707674,2,'17:00','19:00','2017-10-27',0,1);
INSERT INTO Uczestnictwo_w_zajęciach VALUES (10,98100700374,4,'14:00','16:00','2016-10-26',0,1);
INSERT INTO Uczestnictwo_w_zajęciach VALUES (11,96116173214,6,'17:00','19:30','2018-11-02',0,1);
INSERT INTO Uczestnictwo_w_zajęciach VALUES (12,97035113374,8,'10:00','12:00','2017-11-31',0,1);
INSERT INTO Uczestnictwo_w_zajęciach VALUES (13,96011353874,1,'16:00','18:00','2018-10-30',0,1);
INSERT INTO Uczestnictwo_w_zajęciach VALUES (14,96101707674,2,'12:00','13:30','2017-11-03',0,0);
INSERT INTO Uczestnictwo_w_zajęciach VALUES (15,98100700374,4,'14:00','16:00','2016-11-02',0,1);
INSERT INTO Uczestnictwo_w_zajęciach VALUES (16,96110613374,2,'14:00','17:00','2017-10-20',1,0);
INSERT INTO Uczestnictwo_w_zajęciach VALUES (17,96102124374,6,'17:00','19:00','2018-10-26',1,0);
INSERT INTO Uczestnictwo_w_zajęciach VALUES (18,96105862136,5,'10:00','11:30','2018-11-03',1,0);
INSERT INTO Uczestnictwo_w_zajęciach VALUES (19,96108765374,2,'15:00','17:30','2017-10-27',1,0);
INSERT INTO Uczestnictwo_w_zajęciach VALUES (20,98100713109,5,'12:00','13:30','2018-10-20',1,0);

SELECT * FROM Uczestnictwo_w_zajęciach;