2.1.1
SELECT ENAME NAME, 
(SELECT G2.ENAME FROM GEMP G2 WHERE G1.MGR = G2.EMPNO) MANAGER 
FROM GEMP G1;
NAME			  MANAGER
------------------------- -------------------------
SMITH			  FORD
ALLEN			  BLAKE
WARD			  BLAKE
JONES			  KING
MARTIN			  BLAKE
BLAKE			  KING
CLARK			  KING
SCOTT			  JONES
KING
TURNER			  BLAKE
ADAMS			  SCOTT

NAME			  MANAGER
------------------------- -------------------------
JAMES			  BLAKE
FORD			  JONES
MILLER			  CLARK


2.1.2
SELECT ENAME NAME, 
(SELECT G2.ENAME FROM GEMP G2 WHERE G1.MGR = G2.EMPNO) MANAGER 
FROM GEMP G1;

NAME			  MANAGER
------------------------- -------------------------
SMITH			  FORD
ALLEN			  BLAKE
WARD			  BLAKE
JONES			  KING
MARTIN			  BLAKE
BLAKE			  KING
CLARK			  KING
SCOTT			  JONES
KING
TURNER			  BLAKE
ADAMS			  SCOTT

NAME			  MANAGER
------------------------- -------------------------
JAMES			  BLAKE
FORD			  JONES
MILLER			  CLARK


------------------

2.2.1
SELECT EMPNO, ENAME, JOB, MGR
FROM GEMP
START WITH EMPNO = 7698
CONNECT BY PRIOR MGR = EMPNO;

EMPNO ENAME		     JOB		    MGR
---------- ------------------------- --------------- ----------
 7698 BLAKE		     MANAGER		   7839
 7839 KING 		     PRESIDENT

2.2.2
SELECT EMPNO, ENAME, JOB, MGR
FROM GEMP
START WITH ENAME = 'BLAKE'
CONNECT BY PRIOR EMPNO = MGR;

     EMPNO ENAME		     JOB		    MGR
---------- ------------------------- --------------- ----------
      7698 BLAKE		     MANAGER		   7839
      7499 ALLEN		     SALESMAN		   7698
      7521 WARD 		     SALESMAN		   7698
      7654 MARTIN		     SALESMAN		   7698
      7844 TURNER		     SALESMAN		   7698
      7900 JAMES		     CLERK		   7698

2.2.3
SELECT LEVEL, EMPNO, ENAME, JOB, MGR
FROM GEMP
START WITH MGR IS NULL
CONNECT BY PRIOR EMPNO = MGR;

LEVEL	EMPNO ENAME			JOB		       MGR
---------- ---------- ------------------------- --------------- ----------
	 1	 7839 KING			PRESIDENT
	 2	 7566 JONES			MANAGER 	      7839
	 3	 7788 SCOTT			ANALYST 	      7566
	 4	 7876 ADAMS			CLERK		      7788
	 3	 7902 FORD			ANALYST 	      7566
	 4	 7369 SMITH			CLERK		      7902
	 2	 7698 BLAKE			MANAGER 	      7839
	 3	 7499 ALLEN			SALESMAN	      7698
	 3	 7521 WARD			SALESMAN	      7698
	 3	 7654 MARTIN			SALESMAN	      7698
	 3	 7844 TURNER			SALESMAN	      7698

LEVEL	EMPNO ENAME			JOB		       MGR
---------- ---------- ------------------------- --------------- ----------
	 3	 7900 JAMES			CLERK		      7698
	 2	 7782 CLARK			MANAGER 	      7839
	 3	 7934 MILLER			CLERK		      7782

2.2.4
SELECT LEVEL, EMPNO, ENAME, JOB, MGR
FROM GEMP
WHERE ENAME != 'SCOTT'
START WITH MGR IS NULL
CONNECT BY PRIOR EMPNO = MGR;

LEVEL	EMPNO ENAME			JOB		       MGR
---------- ---------- ------------------------- --------------- ----------
	 1	 7839 KING			PRESIDENT
	 2	 7566 JONES			MANAGER 	      7839
	 4	 7876 ADAMS			CLERK		      7788
	 3	 7902 FORD			ANALYST 	      7566
	 4	 7369 SMITH			CLERK		      7902
	 2	 7698 BLAKE			MANAGER 	      7839
	 3	 7499 ALLEN			SALESMAN	      7698
	 3	 7521 WARD			SALESMAN	      7698
	 3	 7654 MARTIN			SALESMAN	      7698
	 3	 7844 TURNER			SALESMAN	      7698
	 3	 7900 JAMES			CLERK		      7698

LEVEL	EMPNO ENAME			JOB		       MGR
---------- ---------- ------------------------- --------------- ----------
	 2	 7782 CLARK			MANAGER 	      7839
	 3	 7934 MILLER			CLERK		      7782

2.2.5
SELECT LEVEL, EMPNO, ENAME, JOB, MGR
FROM GEMP
START WITH ENAME = 'SCOTT'
CONNECT BY PRIOR MGR = EMPNO;

LEVEL	EMPNO ENAME			JOB		       MGR
---------- ---------- ------------------------- --------------- ----------
	 1	 7788 SCOTT			ANALYST 	      7566
	 2	 7566 JONES			MANAGER 	      7839
	 3	 7839 KING			PRESIDENT

2.2.6
SELECT LEVEL, EMPNO, ENAME, MGR, DEPTNO
FROM GEMP 
WHERE DEPTNO = (SELECT DEPTNO FROM GEMP WHERE ENAME = 'JONES')
START WITH MGR IS NULL
CONNECT BY PRIOR EMPNO = MGR;

LEVEL	EMPNO ENAME			       MGR     DEPTNO
---------- ---------- ------------------------- ---------- ----------
	 2	 7566 JONES			      7839	   20
	 3	 7788 SCOTT			      7566	   20
	 4	 7876 ADAMS			      7788	   20
	 3	 7902 FORD			      7566	   20
	 4	 7369 SMITH			      7902	   20

2.2.7
SELECT LEVEL, EMPNO, ENAME, MGR, DEPTNO
FROM GEMP
START WITH ENAME = 'ADAMS'
CONNECT BY PRIOR MGR = EMPNO;

LEVEL	EMPNO ENAME			       MGR     DEPTNO
---------- ---------- ------------------------- ---------- ----------
	 1	 7876 ADAMS			      7788	   20
	 2	 7788 SCOTT			      7566	   20
	 3	 7566 JONES			      7839	   20
	 4	 7839 KING					           10

2.2.8
SELECT LEVEL, COUNT(*)
FROM GEMP
START WITH MGR IS NULL
CONNECT BY PRIOR EMPNO = MGR
GROUP BY LEVEL
ORDER BY LEVEL;

LEVEL   COUNT(*)
---------- ----------
	 1	    1
	 2	    3
	 3	    8
	 4	    2

2.2.9
SELECT LEVEL, AVG(SAL)
FROM GEMP
START WITH MGR IS NULL
CONNECT BY PRIOR EMPNO = MGR
GROUP BY LEVEL
ORDER BY LEVEL;

LEVEL   AVG(SAL)
---------- ----------
	 1	 5000
	 2 2758,33333
	 3    1731,25
	 4	  950
