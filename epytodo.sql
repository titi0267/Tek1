/*
• id (mandatory, not null, auto-increments)
• email (mandatory, not null, unique)
• password (mandatory not null)
• name (mandatory not null)
• firstname (mandatory not null)
• created_at (set to the current datetime by default)



todo table
• id (mandatory not null, auto-increments)
• title (mandatory not null)
• description (mandatory not null)
• created_at (set to the current datetime by default)
• due_time (mandatory, not null, datetime)
• status (not started by default / todo / in progress / done)
• user_id (mandatory, unsigned, reference to the id of the user that get assigned to the task) */

CREATE TABLE IF NOT EXISTS user (
    id int NOT NULL primary key,
    email varchar NOT NULL,
    password varchar NOT NULL,
    name varchar NOT NULL,
    firstname varchar NOT NULL,
    created_at date default(CURRENT_DATE)
);

CREATE TABLE IF NOT EXISTS todo (
    id int NOT NULL primary key,
    title varchar NOT NULL,
    description varchar NOT NULL,
    created_at date default(CURRENT_DATE),
    due_time date NOT NULL,
    status varchar default(NOT_STARTED),
    user_id int UNSIGNED NOT NULL FOREIGN KEY REFERENCES user(id)
);