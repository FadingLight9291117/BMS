
create table user(
id        int primary key auto_increment,
user_name varchar(255) not null,
id_card   bigint(16) unique
);

create table credit_card(
id          int auto_increment,
user_idcard bigint(16) not null,
card_number bigint(16) unique,
password    int(6) default 123456,
phone       bigint(11) not null,
credit_line int default 2000,
balance     int default 0,        
state enum('normal','abnormal','delete') default 'normal',
primary key(id),
foreign key(user_idcard ) references user(id_card)
);

create table deposit_card(
id          int auto_increment,
user_idcard bigint(16) not null,
card_number bigint(16) unique,
password    int(6) default 123456,
phone       bigint(11) not null,
balance     int default 0,        
state enum('normal','abnormal','delete') default 'normal',
primary key(id),
foreign key(user_idcard ) references user(id_card)
);

