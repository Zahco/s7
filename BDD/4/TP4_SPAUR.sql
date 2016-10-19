2.1.a
create or replace trigger triggerMajId
before insert on gmalade
for each row
declare 
  maxID number;
begin
  select max(n_malade)
  into maxID
  from gmalade;
  update gmalade
  set n_malade = maxID + 1
  where n_malade = :new.n_malade;
end;
/
  Trigger created.
  
2.1.b
create or replace trigger triggerLowercase
before insert on gmalade
for each row
begin
  update gmalade
  set nom_malade = lower(:new.nom_malade), prenom_malade = lower(:new.prenom_malade)
  where n_malade = :new.n_malade;
end;
/
  Trigger created.
  
2.2
create or replace trigger triggerNullExamen
before insert on gconsultation
for each row
begin
  update gconsultation
  set examen = 'Visite de routine'
  where n_malade = :new.n_malade
  and :new.examen = ''
  and :new.prescription = '';
end;
/
  Trigger created.
  
2.3
create or replace trigger triggerArchiveConsultation
after delete on gconsultation
for each row
begin
    insert into gconsultation_archive(n_med,n_malade,date_consult,h_consult,prescription,examen) 
    values(:old.n_med,:old.n_malade,:old.date_consult,:old.h_consult,:old.prescription,:old.examen);
end;
/
  Trigger created.
  
2.4
create or replace trigger triggerArchiveNotMove
before update or delete on gconsultation_archive
for each row
begin
  raise_application_error(-20001, 'Archives can not be moved');
end;
/
  Trigger created.
  
2.5.a
create or replace trigger triggerGoodStr
before insert on gmedecin
for each row
begin
  if not REGEXP_LIKE(:new.identite_med, '^[A-Z].[a-z]* [A-Z]*$') then
    raise_application_error(-20002, 'Archives can not be moved');
  end if;
end;
/
2.5.b
create or replace trigger triggerGoodStr
before insert on gmedecin
for each row
begin
  if not REGEXP_LIKE(:new.identite_med, '^[A-Z][a-z]+ [A-Z]+$', 'm') then
    raise_application_error(-20002, 'identite_med not match');
  end if;
  if not REGEXP_LIKE(:new.adr_elec_med, '^[A-Za-z0-9.]*@[A-Za-z0-9]*.[a-z]*$') then
    raise_application_error(-20003, 'adr_elec_med not match');
  end if;
end;
/
  Trigger created.
