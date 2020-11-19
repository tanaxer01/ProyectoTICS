<?php
$servername = "localhost";
$username = "root";
$db= "usuarios";
$password = "";

// Create connection
$conn = new mysqli($servername, $username, $password,$db);

// Check connection
if ($conn->connect_error) {
  die("Connection failed: " . $conn->connect_error);
}
echo "Connected successfully";

$valor = 0;
if ($valor== 1){
    // sql to create table
    $sql = "CREATE TABLE personas (
        id INT(6) UNSIGNED AUTO_INCREMENT PRIMARY KEY,
        nombre VARCHAR(30) NOT NULL,
        contraseña VARCHAR(30) NOT NULL
        )";
        
        if ($conn->query($sql) === TRUE) {
        echo "Table MyGuests created successfully";
        } else {
        echo "Error creating table: " . $conn->error;
        }
    }   
$conn->close();

?>