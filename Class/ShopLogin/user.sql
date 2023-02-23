

CREATE TABLE users (
user_id MEDIUMINT UNSIGNED NOT NULL AUTO_INCREMENT,
first_name VARCHAR(20) NOT NULL,
last_name VARCHAR(40) NOT NULL,
email VARCHAR(60) NOT NULL,
pass CHAR(40) NOT NULL,
registration_date DATETIME NOT NULL,
PRIMARY KEY (user_id)
);

INSERT INTO users 
(first_name, last_name, email, pass, registration_date) 
VALUES ('Larry', 'Ullman', 'email@example.com', SHA1('mypass'), NOW());

INSERT INTO users VALUES 
(NULL, 'Zoe', 'Isabella', 'email2@example.com', SHA1('mojito'), NOW());

INSERT INTO users (first_name, last_name, email, pass, registration_date) VALUES
('John', 'Lennon', 'john@beatles.com', SHA1('Happin3ss'), NOW()),
('Paul', 'McCartney', 'paul@beatles.com', SHA1('letITbe'), NOW()),
('George', 'Harrison', 'george@beatles.com ', SHA1('something'), NOW()),
('Ringo', 'Starr', 'ringo@beatles.com', SHA1('thisboy'), NOW());

INSERT INTO users (first_name, last_name, email, pass, registration_date) VALUES
('David', 'Jones', 'davey@monkees.com', SHA1('fasfd'), NOW()),
('Peter', 'Tork', 'peter@monkees.com', SHA1('warw'), NOW()),
('Micky', 'Dolenz', 'micky@monkees.com ', SHA1('afsa'), NOW()),
('Mike', 'Nesmith', 'mike@monkees.com', SHA1('abdfadf'), NOW()),
('David', 'Sedaris', 'david@authors.com', SHA1('adfwrq'), NOW()),
('Nick', 'Hornby', 'nick@authors.com', SHA1('jk78'), NOW()),
('Melissa', 'Bank', 'melissa@authors.com', SHA1('jhk,h'), NOW()),
('Toni', 'Morrison', 'toni@authors.com', SHA1('hdhd'), NOW()),
('Jonathan', 'Franzen', 'jonathan@authors.com', SHA1('64654'), NOW()),
('Don', 'DeLillo', 'don@authors.com', SHA1('asf8'), NOW()),
('Graham', 'Greene', 'graham@authors.com', SHA1('5684eq'), NOW()),
('Michael', 'Chabon', 'michael@authors.com', SHA1('srw6'), NOW()),
('Richard', 'Brautigan', 'richard@authors.com', SHA1('zfs654'), NOW()),
('Russell', 'Banks', 'russell@authors.com', SHA1('wwr321'), NOW()),
('Homer', 'Simpson', 'homer@simpson.com', SHA1('5srw651'), NOW()),
('Marge', 'Simpson', 'marge@simpson.com', SHA1('ljsa'), NOW()),
('Bart', 'Simpson', 'bart@simpson.com', SHA1('pwqojz'), NOW()),
('Lisa', 'Simpson', 'lisa@simpson.com', SHA1('uh6'), NOW()),
('Maggie', 'Simpson', 'maggie@simpson.com', SHA1('plda664'), NOW()),
('Abe', 'Simpson', 'abe@simpson.com', SHA1('qopkrokr65'), NOW());
