<?php 

$conn= pg_connect("host=localhost dbname=postgres user=postgres password=123 port= 5432") or die('No se ha podido conectar: ' . pg_last_error());

function conectar_PostgreSQL( $usuario, $pass, $host, $bd )
    {
         $conexion = pg_connect( "user=".$usuario." ".
                                "password=".$pass." ".
                                "host=".$host." ".
                                "dbname=".$bd
                               ) or die( "Error al conectar: ".pg_last_error() );
        return $conexion;
    }



function borrarPersona( $conexion, $id )
    {
        $sql = "DELETE FROM personas";
        // Si 'id' es diferente de 'null' sólo se borra la persona con el 'id' especificado:
        if( $id != null )
            $sql .= " WHERE personas.usuario=".$id;
        // Ejecutamos la consulta (se devolverá true o false):
         return pg_query( $conexion, $sql );
        }


function listarPersonas( $conexion )
{
    $sql = "SELECT * FROM personas";
    $ok = true;
    // Ejecutar la consulta:
        $rs = pg_query( $conexion, $sql );
    if( $rs )
    {
        // Obtener el número de filas:
            if( pg_num_rows($rs) > 0 )
        {
            echo "<p/>LISTADO DE PERSONAS<br/>";
            echo "===================<p />";
            // Recorrer el resource y mostrar los datos:
                while( $obj = pg_fetch_object($rs) )
                    echo $obj->usuario." - ".$obj->pass."<br />";
        }
        else
            echo "<p>No se encontraron personas</p>";
    }
    else
        $ok = false;
    return $ok;
}


$coco= conectar_PostgreSQL('postgres', 123, 'localhost', 'tics');


$hola = listarPersonas($coco);

?>