create or replace type caracteristique_type as object (
  description varchar(255)
);
/
create or replace type caracteristiques_type as table of ref caracteristique_type;
/

drop table patient;
create table caracteristique of caracteristique_type ;

create or replace type patient_type as object (
  nom varchar(255),
  prenom varchar(255),
  age number,
  lescaracteristiques caracteristiques_type
);
/

drop table patient;
create table patient of patient_type 
nested table lescaracteristiques store as caracteristiquesTable;

