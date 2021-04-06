CREATE TABLE IF NOT EXISTS user (
    id int NOT NULL primary key AUTO_INCREMENT,
    email varchar(255) NOT NULL,
    password varchar(255) NOT NULL,
    name varchar(255) NOT NULL,
    firstname varchar(255) NOT NULL,
    created_at date default(CURRENT_DATE)
);

CREATE TABLE IF NOT EXISTS todo (
    id int NOT NULL primary key AUTO_INCREMENT,
    title varchar(255) NOT NULL,
    description varchar(255) NOT NULL,
    created_at date default(CURRENT_DATE),
    due_time date NOT NULL,
    status enum('not started', 'in progress', 'done') NOT NULL default('not started'),
    user_id int UNSIGNED NOT NULL FOREIGN KEY REFERENCES user(id)
);