ALTER  TABLE HISTORICO ADD FOREIGN KEY (MATRICULA) REFERENCES ALUNO (MATRICULA);
ALTER  TABLE HISTORICO ADD FOREIGN KEY (CODIGO) REFERENCES DISCIPLINA (CODIGO);
