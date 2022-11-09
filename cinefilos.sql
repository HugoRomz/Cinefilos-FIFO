//Agregar telefono a socio

CREATE DATABASE cinefilos;

\c cinefilos;


CREATE TABLE local(
    id_local serial NOT NULL  PRIMARY KEY,
    nombreLocal text,
    direccion text,
    ciudad text
);
CREATE TABLE genero (
        id_genero serial NOT NULL PRIMARY KEY,
        nombreG text
);
CREATE TABLE pelicula(
    id_pelicula serial NOT NULL  PRIMARY KEY,
    titulo text,
    director text,
    precio float,
    stock int,
    id_local int,
    status int,
    FOREIGN KEY (id_local) REFERENCES local(id_local)
);
CREATE TABLE genero_pelicula(
    id_pelicula int,
    id_genero int,
    FOREIGN KEY (id_pelicula) REFERENCES pelicula(id_pelicula),
    FOREIGN KEY (id_genero) REFERENCES genero(id_genero),
    PRIMARY KEY(id_pelicula,id_genero)
);


CREATE TABLE socio(
    id_socio serial NOT NULL  PRIMARY KEY,
    nombres text,
    apellidos text,
    curp text,
    telefeno text,
    direccion text,
    tipo text,
    statusM int
);

CREATE TABLE renta(
    id_renta serial NOT NULL  PRIMARY KEY,
    id_socio int,
    id_local int,
    status int,
    exedente float,
    descuento float,
    total int,
    FOREIGN KEY (id_socio) REFERENCES socio(id_socio),
    FOREIGN KEY (id_local) REFERENCES local(id_local)
);
CREATE TABLE det_renta(
    cns serial,
    id_renta int,
    id_pelicula int,
    cantidad int,
    fecha_entrada date,
    fecha_salida date,
    subtotal float,
    FOREIGN KEY (id_renta) REFERENCES renta(id_renta),
    FOREIGN KEY (id_pelicula) REFERENCES pelicula(id_pelicula),
    PRIMARY KEY(cns,id_renta)
);


-- GENEROS

INSERT INTO genero(nombreg) VALUES ('Drama');
INSERT INTO genero(nombreg) VALUES ('Crimenes');
INSERT INTO genero(nombreg) VALUES ('Western');
INSERT INTO genero(nombreg) VALUES ('Accion');
INSERT INTO genero(nombreg) VALUES ('Belico');
INSERT INTO genero(nombreg) VALUES ('Fantasia');
INSERT INTO genero(nombreg) VALUES ('Suspenso');
INSERT INTO genero(nombreg) VALUES ('Ciencia Ficcion');
INSERT INTO genero(nombreg) VALUES ('Misterio');
INSERT INTO genero(nombreg) VALUES ('Terror');
INSERT INTO genero(nombreg) VALUES ('Romance');
INSERT INTO genero(nombreg) VALUES ('Aventura');
INSERT INTO genero(nombreg) VALUES ('Thriller');
INSERT INTO genero(nombreg) VALUES ('Sci-Fi');
INSERT INTO genero(nombreg) VALUES ('Guerra');
INSERT INTO genero(nombreg) VALUES ('Comedia');
INSERT INTO genero(nombreg) VALUES ('Anime');
INSERT INTO genero(nombreg) VALUES ('Family');
INSERT INTO genero(nombreg) VALUES ('No Especificado'); -- id_genero 19

-- PELICULAS

INSERT INTO pelicula(titulo,director,stock,precio) VALUES ('Sueño de fuga','Frank Darabont',20,25);
INSERT INTO pelicula(titulo,director,stock,precio) VALUES ('El padrino','Francis Ford Coppola',15,40);
INSERT INTO pelicula(titulo,director,stock,precio) VALUES ('El padrino parte 2','Francis Ford Coppola',20,30);
INSERT INTO pelicula(titulo,director,stock,precio) VALUES ('Tiempos violentos','Quentin Tarantino',20,30);
INSERT INTO pelicula(titulo,director,stock,precio) VALUES ('El Bueno, el Feo y el Malo','Sergio Leone',20,30);
INSERT INTO pelicula(titulo,director,stock,precio) VALUES ('Batman: el caballero de la noche','Christopher Nolan',25,50);
INSERT INTO pelicula(titulo,director,stock,precio) VALUES ('12 Hombres sin Piedad','Sidney Lumet',20,30);
INSERT INTO pelicula(titulo,director,stock,precio) VALUES ('La lista de Schindler','Steven Spielberg',15,30);
INSERT INTO pelicula(titulo,director,stock,precio) VALUES ('El Señor de los Anillos: el retorno del Rey','Peter Jackson',27,40);
INSERT INTO pelicula(titulo,director,stock,precio) VALUES ('El club de la pelea','David Fincher',15,30);
INSERT INTO pelicula(titulo,director,stock,precio) VALUES ('Star Wars: Episodio V - El Imperio contraataca','George Lucas',15,30);
INSERT INTO pelicula(titulo,director,stock,precio) VALUES ('El señor de los anillos: la comunidad del anillo','Peter Jackson',15,30);
INSERT INTO pelicula(titulo,director,stock,precio) VALUES ('El origen','Christopher Nolan',15,30);
INSERT INTO pelicula(titulo,director,stock,precio) VALUES ('Buenos muchachos','Martin Scorsese',15,30);
INSERT INTO pelicula(titulo,director,stock,precio) VALUES ('Star Wars: episodio IV - una nueva esperanza','George Lucas',15,30);
INSERT INTO pelicula(titulo,director,stock,precio) VALUES ('Los siete samuráis','Akira Kurosawa',15,30);
INSERT INTO pelicula(titulo,director,stock,precio) VALUES ('Forrest Gump','Robert Zemeckis',15,30);
INSERT INTO pelicula(titulo,director,stock,precio) VALUES ('The Matrix','Wachowski Sisters',55,30);
INSERT INTO pelicula(titulo,director,stock,precio) VALUES ('El Señor de los Anillos: las dos torres','Peter Jackson',15,30);
INSERT INTO pelicula(titulo,director,stock,precio) VALUES ('Ciudad de Dios','Kátia Lund',15,30);
INSERT INTO pelicula(titulo,director,stock,precio) VALUES ('Se7en: los siete pecados capitales','David Fincher',15,30);
INSERT INTO pelicula(titulo,director,stock,precio) VALUES ('El silencio de los inocentes','Jonathan Demme',15,30);
INSERT INTO pelicula(titulo,director,stock,precio) VALUES ('Once upon a time in the west','Sergio Leone',15,30);
INSERT INTO pelicula(titulo,director,stock,precio) VALUES ('Casablanca','Michael Curtiz',15,30);
INSERT INTO pelicula(titulo,director,stock,precio) VALUES ('Los sospechosos de siempre','Jonathan Demme',15,30);
INSERT INTO pelicula(titulo,director,stock,precio) VALUES ('Indiana Jones y los cazadores del arca perdida','Steven Spielberg',15,30);
INSERT INTO pelicula(titulo,director,stock,precio) VALUES ('Rear Window','Alfred Hitchcock',15,30);
INSERT INTO pelicula(titulo,director,stock,precio) VALUES ('¡Que bello es vivir!','Frank Capra',15,30);
INSERT INTO pelicula(titulo,director,stock,precio) VALUES ('American History X','Tony Kaye',15,30);
INSERT INTO pelicula(titulo,director,stock,precio) VALUES ('Apocalipsis ahora','Francis Ford Coppola',15,30);
INSERT INTO pelicula(titulo,director,stock,precio) VALUES ('Terminator 2: el juicio final','James Cameron',15,30);
INSERT INTO pelicula(titulo,director,stock,precio) VALUES ('Salvando al soldado Ryan','Steven Spielberg',15,30);
INSERT INTO pelicula(titulo,director,stock,precio) VALUES ('Amnesia','Christopher Nolan',15,30);
INSERT INTO pelicula(titulo,director,stock,precio) VALUES ('Alien','Ridley Scott',15,30);
INSERT INTO pelicula(titulo,director,stock,precio) VALUES ('Modern Times','Charlie Chaplin',15,30);
INSERT INTO pelicula(titulo,director,stock,precio) VALUES ('El viaje de Chihiro','Hayao Miyazaki',15,30);
INSERT INTO pelicula(titulo,director,stock,precio) VALUES ('Intriga Internacional','Alfred Hitchcock',15,30);
INSERT INTO pelicula(titulo,director,stock,precio) VALUES ('Volver al futuro','Robert Zemeckis',15,30);
INSERT INTO pelicula(titulo,director,stock,precio) VALUES ('La vita è bella','Roberto Benigni',15,30);
INSERT INTO pelicula(titulo,director,stock,precio) VALUES ('El resplandor','Stanley Kubrick',15,30);
INSERT INTO pelicula(titulo,director,stock,precio) VALUES ('El pianista','Roman Polanski',15,30);
INSERT INTO pelicula(titulo,director,stock,precio) VALUES ('El ciudadano Kane','Orson Welles',15,30);
INSERT INTO pelicula(titulo,director,stock,precio) VALUES ('Los infiltrados','Martin Scorsese',15,30);


--GENERO-PELICULA


INSERT INTO genero_pelicula(id_pelicula,id_genero) VALUES (1,1);
INSERT INTO genero_pelicula(id_pelicula,id_genero) VALUES (2,2);
INSERT INTO genero_pelicula(id_pelicula,id_genero) VALUES (3,2);
INSERT INTO genero_pelicula(id_pelicula,id_genero) VALUES (4,2);
INSERT INTO genero_pelicula(id_pelicula,id_genero) VALUES (5,3);
INSERT INTO genero_pelicula(id_pelicula,id_genero) VALUES (6,4);
INSERT INTO genero_pelicula(id_pelicula,id_genero) VALUES (7,1);
INSERT INTO genero_pelicula(id_pelicula,id_genero) VALUES (8,5);
INSERT INTO genero_pelicula(id_pelicula,id_genero) VALUES (9,6);
INSERT INTO genero_pelicula(id_pelicula,id_genero) VALUES (10,7);
INSERT INTO genero_pelicula(id_pelicula,id_genero) VALUES (11,8);
INSERT INTO genero_pelicula(id_pelicula,id_genero) VALUES (12,6);
INSERT INTO genero_pelicula(id_pelicula,id_genero) VALUES (13,8);
INSERT INTO genero_pelicula(id_pelicula,id_genero) VALUES (14,2);
INSERT INTO genero_pelicula(id_pelicula,id_genero) VALUES (15,8);
INSERT INTO genero_pelicula(id_pelicula,id_genero) VALUES (16,4);
INSERT INTO genero_pelicula(id_pelicula,id_genero) VALUES (17,1);
INSERT INTO genero_pelicula(id_pelicula,id_genero) VALUES (18,8);
INSERT INTO genero_pelicula(id_pelicula,id_genero) VALUES (19,6);
INSERT INTO genero_pelicula(id_pelicula,id_genero) VALUES (20,5);
INSERT INTO genero_pelicula(id_pelicula,id_genero) VALUES (21,9);
INSERT INTO genero_pelicula(id_pelicula,id_genero) VALUES (22,10);
INSERT INTO genero_pelicula(id_pelicula,id_genero) VALUES (23,3);
INSERT INTO genero_pelicula(id_pelicula,id_genero) VALUES (24,11);
INSERT INTO genero_pelicula(id_pelicula,id_genero) VALUES (25,10);
INSERT INTO genero_pelicula(id_pelicula,id_genero) VALUES (26,12);
INSERT INTO genero_pelicula(id_pelicula,id_genero) VALUES (27,13);
INSERT INTO genero_pelicula(id_pelicula,id_genero) VALUES (28,10);
INSERT INTO genero_pelicula(id_pelicula,id_genero) VALUES (29,1);
INSERT INTO genero_pelicula(id_pelicula,id_genero) VALUES (30,5);
INSERT INTO genero_pelicula(id_pelicula,id_genero) VALUES (31,14);
INSERT INTO genero_pelicula(id_pelicula,id_genero) VALUES (32,15);
INSERT INTO genero_pelicula(id_pelicula,id_genero) VALUES (33,9);
INSERT INTO genero_pelicula(id_pelicula,id_genero) VALUES (34,14);
INSERT INTO genero_pelicula(id_pelicula,id_genero) VALUES (35,16);
INSERT INTO genero_pelicula(id_pelicula,id_genero) VALUES (36,17);
INSERT INTO genero_pelicula(id_pelicula,id_genero) VALUES (37,7);
INSERT INTO genero_pelicula(id_pelicula,id_genero) VALUES (38,8);
INSERT INTO genero_pelicula(id_pelicula,id_genero) VALUES (39,15);
INSERT INTO genero_pelicula(id_pelicula,id_genero) VALUES (40,10);
INSERT INTO genero_pelicula(id_pelicula,id_genero) VALUES (41,5);
INSERT INTO genero_pelicula(id_pelicula,id_genero) VALUES (42,1);
INSERT INTO genero_pelicula(id_pelicula,id_genero) VALUES (43,2);


--LOCAL
INSERT INTO local(nombrelocal,direccion,ciudad) VALUES ('Cinefilos El Original','Central Sur 7b, Los Naranjos, Centro, 30830 Tapachula de Córdova y Ordoñez, Chis.','Tapachula');
INSERT INTO local(nombrelocal,direccion,ciudad) VALUES ('Cinefilos Los hijos del Original','Octava Avenida Nte. 43, Los Naranjos, Centro, 30830 Tapachula de Córdova y Ordoñez, Chis.','Tapachula');
INSERT INTO local(nombrelocal,direccion,ciudad) VALUES ('Cinefilos Galerias','Galerias Tapachula, Los Naranjos, Tapachula, Chis.','Tapachula');

--Renta
insert into renta (id_socio,id_local,status)values(1,3,0);

--Detalle_renta
insert into det_renta (id_renta,id_pelicula,cantidad,fecha_salida)values(1,2,1,'2022-01-11');

--////////////////////////////////////////////////////////////////////

CREATE OR REPLACE FUNCTION regresar_stock () RETURNS TRIGGER
AS
$$
    DECLARE 
        nuevo_valor int;
        _status int;
        _id_pelicula int;
    BEGIN
        select status into _status from renta where id_renta = new.id_renta;
      
        if(_status > 0 ) then 
            UPDATE pelicula SET stock = stock+1 WHERE id_pelicula in (select id_pelicula from det_renta inner join renta on det_renta.id_renta = renta.id_renta and renta.id_socio = new.id_socio);
        else
            
        end if;
        RETURN NEW;
    END;
$$
LANGUAGE plpgsql;
CREATE TRIGGER TR_REG_STOCK after update ON renta
for each row
execute procedure regresar_stock();

--/////////////////////////////////////////////////////////////////////

CREATE OR REPLACE FUNCTION calcular_por_fechas () RETURNS TRIGGER
AS
$BODY$
    DECLARE 
        dias int;
    BEGIN
        select (fecha_entrada-fecha_salida)into dias from det_renta inner join renta on det_renta.id_renta = renta.id_renta and cns = new.cns;
        if(dias <= 5) then
            UPDATE renta SET descuento = (0.1), exedente = 0 WHERE id_renta = NEW.id_renta;
        else
            UPDATE renta SET exedente = (dias * 10), descuento = 0 WHERE id_renta = NEW.id_renta;
        end if;
        RETURN NEW;
    END;
$BODY$
LANGUAGE plpgsql;
CREATE TRIGGER TR_UPDATE_FECHA after UPDATE ON det_renta
for each row
execute procedure calcular_por_fechas();

--/////////////////////////////////////////////////////////////////////////////////////////////////

CREATE OR REPLACE FUNCTION checar_stock () RETURNS TRIGGER
AS
$$
    DECLARE 
        total int;
        _subtotal NUMERIC;
        
    BEGIN
        SELECT stock into total FROM pelicula INNER JOIN det_renta ON pelicula.id_pelicula = det_renta.id_pelicula AND cns = new.cns;
        SELECT (precio*det_renta.cantidad) INTO _subtotal FROM det_renta INNER JOIN pelicula ON det_renta.id_pelicula = pelicula.id_pelicula and cns = new.cns;
--         UPDATE det_renta SET subtotal = _subtotal WHERE cns = NEW.cns;
        if (SELECT stock FROM pelicula INNER JOIN det_renta ON pelicula.id_pelicula = det_renta.id_pelicula AND cns = new.cns) > 0 then
            UPDATE pelicula SET stock = stock-1 WHERE id_pelicula = NEW.id_pelicula;
            UPDATE det_renta SET subtotal = _subtotal WHERE cns = NEW.cns;
        else
             RAISE EXCEPTION  'todas las copias estan rentadas, no puedes rentar';
--              ROLLBACK;
        end if;
        RETURN NEW;
        
      
    END;
$$
LANGUAGE plpgsql;
CREATE TRIGGER TR_CHECK_STOCK AFTER INSERT ON det_renta
for each row
execute procedure checar_stock();

--//////////////////////////////////////////////////////////////////////////////////////////////////////////




CREATE OR REPLACE FUNCTION cargar_total () RETURNS TRIGGER
AS
$$
    DECLARE 
        _subtotal NUMERIC :=0;
        _importe_total NUMERIC :=0;
        _descuento NUMERIC :=0;
        _exedente NUMERIC :=0;     
    BEGIN
    
        SELECT SUM(subtotal) INTO _importe_total FROM det_renta where id_renta = new.id_renta;
        
        select exedente into _exedente from renta inner join det_renta on renta.id_renta = det_renta.id_renta;
--         select descuento from renta inner join det_renta on renta.id_renta = det_renta.id_renta and cns =81;
        if(select exedente from renta where id_renta = new.id_renta)>0 then 
             UPDATE renta SET total = (_importe_total+_exedente) WHERE id_renta = NEW.id_renta;
        elseif(select descuento from renta where id_renta = new.id_renta)>0 then
             UPDATE renta SET total = (_importe_total-(_importe_total*0.1)) WHERE id_renta = NEW.id_renta;
        else
        
        end if;
        RETURN NEW;
    END;
$$
LANGUAGE plpgsql;
-- CREACION DEL TRIGGER para crear el importe automaticamente
CREATE TRIGGER TR_INSERT_total AFTER update ON det_renta
for each row
execute procedure cargar_total();

--/////////////////////////////////////////////////////////////////////////////////////7


CREATE OR REPLACE FUNCTION calcular_por_fechas () RETURNS TRIGGER
AS
$BODY$
    DECLARE 
        dias int;
    BEGIN
        select (fecha_entrada-fecha_salida)into dias from det_renta inner join renta on det_renta.id_renta = renta.id_renta and cns = new.cns;
        if(dias <= 5) then
            UPDATE renta SET descuento = (0.1), exedente = 0 WHERE id_renta = NEW.id_renta;
        else
            UPDATE renta SET exedente = (dias * 10), descuento = 0 WHERE id_renta = NEW.id_renta;
        end if;
        RETURN NEW;
    END;
$BODY$
LANGUAGE plpgsql;
CREATE TRIGGER TR_UPDATE_FECHA after UPDATE ON det_renta
for each row
execute procedure calcular_por_fechas();


--CONSULTA DE GENERO PELICULA
select pelicula.titulo,pelicula.director,pelicula.stock,genero.nombreg from pelicula,genero,genero_pelicula as gp where gp.id_pelicula=pelicula.id_pelicula and gp.id_genero=genero.id_genero ORDER BY gp.id_pelicula;
 

 --CONSULTA PELICULAS CCFICCION
SELECT p.id_local,l.nombrelocal, p.titulo,gp.id_genero

FROM pelicula AS p

INNER JOIN local AS l ON p.id_local = l.id_local
INNER JOIN genero_pelicula as gp ON gp.id_pelicula = p.id_pelicula and gp.id_genero = 4;


--consulta que devuelve los socios que han rentado, mostrando: nombre completo, direccion, telefono, titulo de la pelicula, fecha de renta
SELECT t1.id_socio,t1.nombre,t1.apellidos,t1.direccion,p1.titulo,t3.fecha_salida FROM socio t1 
                inner join renta t2 ON t2.id_socio = t1.id_socio 
                        inner join det_renta t3 ON t3.id_renta = t2.id_renta
                            inner join pelicula p1 on p1.id_pelicula = t3.id_pelicula;



 
 