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

  CHECK (sessao in ('Centra', 'Vendas', 'Comercial')),
  PRIMARY KEY (codigo)  
);


