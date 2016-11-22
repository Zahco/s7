-- 2.1.1

create type qualif_type as object(
  qualification varchar(255),
  tarif number
);
/
-- Type created.

-- 2.1.2
create table qualif of qualif_type;

--Table created.
insert into qualif(qualification, tarif) values ('Développeur', 500);
insert into qualif(qualification, tarif) values ('Analyste', 700);
insert into qualif(qualification, tarif) values ('Chef de projet', 900);
insert into qualif(qualification, tarif) values ('Consultant', 1000);
insert into qualif(qualification, tarif) values ('Directeur commercial', 1300);

-- 2.1.3
describe qualif;
describe qualif_type;
select * from qualif;

-- 2.1.4
select qualification from qualif order by qualification;

-- 2.1.5
select avg(tarif) from qualif;
-- 880

-- 2.1.6
update qualif set tarif = tarif * 1.025;
select * from qualif;


-- 2.2.1
drop table qualif;
create table qualif (qualification qualif_type);
insert into qualif values (qualif_type('Développeur', 500));
insert into qualif values (qualif_type('Analyste', 700));
insert into qualif values (qualif_type('Chef de projet', 900));
insert into qualif values (qualif_type('Consultant', 1000));
insert into qualif values (qualif_type('Directeur commercial', 1300));

-- 2.2.2
describe qualif;
select * from qualif;
select min(q.qualification.tarif) as minimum, max(q.qualification.tarif) as maximum from qualif q;

-- 2.2.3
update qualif q set q.qualification.tarif = q.qualification.tarif * 1.1;



-- 2.3.1
create table intervenant (
  matricule number constraint pk primary key,
  nom varchar(10),
  prenom varchar(10),
  qualification qualif_type
);

-- 2.3.2
describe intervenant;

-- 2.3.3
insert into intervenant values (2516, 'Dupont', 'Pierre', qualif_type('Développeur', 550));
insert into intervenant values (7655, 'Henri', 'Jacques', qualif_type('Consultant', 990.90));
insert into intervenant values (7687, 'Triolet', 'Elsa', qualif_type('Consultant', 1029));

-- 2.3.4
select nom, i.qualification.tarif from intervenant i;

-- 2.3.5
select matricule, nom from intervenant i where i.qualification.qualification = 'Consultant';

-- 2.3.6
select i.prenom, i.nom, i.qualification.tarif - q.qualification.tarif as différence from intervenant i, qualif q 
where i.qualification.qualification = q.qualification.qualification 
and i.qualification.tarif >= q.qualification.tarif;

-- 2.3.7
-- Perte de données

-- 2.3.8
-- ils vécurent heureux et eurent beaucoups d'enfants.
