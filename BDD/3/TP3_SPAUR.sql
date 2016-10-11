2.1
ALTER TABLE gmedecin ADD salaire integer default 2000 not null;
  Table altered.

2.2
set serveroutput on;

create or replace procedure tp3_2_2 is
begin
  delete 
  from gmedecin 
  where statut='PATTASS' 
  and prof_serv='Florence ROUSSEAU';
  if sql%rowcount = 0 then
    DBMS_OUTPUT.PUT_LINE('Aucune ligne affectée');
  else
    DBMS_OUTPUT.PUT_LINE(sql%rowcount || ' lignes affectées');
  end if;
end;
/
  Procedure created.

2.3

create or replace function tp3_2_3 (id_medic integer, mon integer, yea integer)
return real is ret real;
begin
  select count(*) into ret
  from gconsultation
  where n_med = id_medic
  and extract(month from date_consult) = mon
  and extract(year from date_consult) = yea;
  return ret;
end;
/
  Procedure created.

create or replace procedure print_tp3_2_3 is
begin
  DBMS_OUTPUT.PUT_LINE(tp3_2_3(131,10,2011) || ' consultations');
end;
/
  Procedure created.

execute print_tp3_2_3;
  5 consultations

  PL/SQL procedure successfully completed.

2.4

create or replace procedure tp3_2_4 is
begin
  update gmedecin set salaire = salaire + salaire * 0.08 where statut = 'PUPH';
  update gmedecin set salaire = salaire + salaire * 0.05 where statut = 'PATT';
  update gmedecin set salaire = salaire + salaire * 0.02 where statut != 'PUPH' and statut != 'PATT';
end;
/
  Procedure created.
