-- 2.1.1
create type intervenant_type as object(
  mat number,
  nom varchar(15),
  prenom varchar(15),
  tarifApplique number,
  qualification qualif_type
);
/

create type mission_type as object(
  code varchar(15),
  intitule varchar(100),
  nbJours number,
  intervenant ref intervenant_type
);
/

-- 2.1.2
create table intervenant of intervenant_type;

-- 2.1.3
insert into intervenant values (2516, 'Dupont', 'Pierre', 0, qualif_type('Développeur', 550));
insert into intervenant values (7655, 'Henri', 'Jacques', 0, qualif_type('Consultant', 990.90));
insert into intervenant values (7687, 'Triolet', 'Elsa', 0, qualif_type('Consultant', 1029));

-- 2.1.4
insert into mission values ('Valarpain033', 'Etude technique du passage de PEL en CEL', 54, (select REF(i) from intervenant i where mat = 7655));
insert into mission values ('Armoni002', 'Prise de contact avec le Directeur', 2, (select REF(i) from intervenant i where mat = 1000));

-- 2.1.5
insert into intervenant values (1000, 'Philippe', 'Michelin', 0, qualif_type('Directeur', 3000));


-- 2.1.6
select REF(i) from intervenant i where mat = 1000;
--0000280209421CFC7DB9EC1464E050820A0EA35B40421CFC7DB9E71464E050820A0EA35B4001004BAF0003

-- 2.1.11
describe mission;
-- Name					   Null?    Type
-- ------------------------------------------------
-- CODE						          VARCHAR2(15)
-- INTITULE					        VARCHAR2(100)
-- NBJOURS					        NUMBER
-- INTERVENANT					    REF OF INTERVENANT_TYPE


-- 2.1.12
select code, nbJours * deref(intervenant).qualification.tarif as cout from mission;
-- CODE		            COUT
-- --------------- -------
-- Valarpain033	   53508,6
-- Armoni002          6000


-- 2.1.13
update mission set nbJours = 3 where code = 'Armoni002';

-- 2.1.14 
update intervenant set qualification = qualif_type('Directeur', 2800) where mat = 1000;

-- 2.1.15
delete from intervenant where mat = 1000;
-- CODE		            COUT
-- --------------- -------
-- Valarpain033	   53508,6
-- Armoni002


-- 2.2.1
create type missions_type as table of mission_type;
/

-- 2.2.2
create table projet(
  nom varchar(20) constraint pk_nom primary key,
  lesMissions missions_type,
  dateDebut date,
  dateFin date
) nested table lesMissions store as missionsTable;

-- 2.2.3


-- 2.2.4
describe projet;


--------------------------------------------------------------------------------
--------------------------------------------------------------------------------
--------------------------------------------------------------------------------
