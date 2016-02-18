CREATE TABLE IF NOT EXISTS Curso (
  codigo INTEGER NOT NULL,
  nome VARCHAR(10) NOT NULL,
  incritos INTEGER,

  CHECK (inscritos >= 0),
  PRIMARY KEY (codigo)  
);

CREATE TABLE IF NOT EXISTS Instrutor (
  codigo INTEGER NOT NULL,
  nome VARCHAR(100) NOT NULL,
  secao VARCHAR(50),
  escritorio VARCHAR(30),
  fone VARCHAR(15),

  CHECK (secao in ('Centra', 'Vendas', 'Comercial')),
  PRIMARY KEY (codigo)  
);

CREATE TABLE IF NOT EXISTS Horario (
  codigo INTEGER NOT NULL,
  sala VARCHAR(30) NOT NULL,
  horario TIME NOT NULL,

  PRIMARY KEY (codigo)  
);

CREATE TABLE IF NOT EXISTS Pre_Req (
  codigo_curso INTEGER NOT NULL,
  pre_req      INTEGER NOT NULL,
  
  PRIMARY KEY (codigo_curso, pre_req),
  FOREIGN KEY (codigo_curso) REFERENCES Curso (codigo),
  FOREIGN KEY (pre_req) REFERENCES Curso (codigo)  
);

CREATE TABLE IF NOT EXISTS Ministrado (
  data DATE  NOT NULL,
  codigo_horario INTEGER NOT NULL,
  codigo_curso   INTEGER NOT NULL,
  codigo_instrutor INTEGER  NOT NULL,

  PRIMARY KEY (data),
  FOREIGN KEY (codigo_horario) REFERENCES Horario (codigo),  
  FOREIGN KEY (codigo_curso) REFERENCES Curso (codigo),  
  FOREIGN KEY (codigo_instrutor) REFERENCES Instrutor (codigo)  
);

