<?php

include_once 'db.php';

class User extends DB{

    private $nombre;
    private $username;
    private $rut;
    private $ramo;
    private $nota;
    private $ponderacion;
    private $prom;
    private $c;
    //private $nombre_nota;

    
//Ejemplos

    public function userExists($user, $pass){
        $md5pass = md5($pass);

        $query = $this->connect()->prepare('SELECT * FROM usuarios WHERE username = :user AND password = :pass');
        $query->execute(['user' => $user, 'pass' => $md5pass]);

        if($query->rowCount()){
            return true;
        }else{
            return false;
        }
    }

    public function setUser($user){
        $query = $this->connect()->prepare('SELECT * FROM usuarios WHERE username = :user');
        $query->execute(['user' => $user]);

        foreach ($query as $currentUser) {
            $this->nombre = $currentUser['nombre'];
            $this->username = $currentUser['username'];
            $this->rut = $currentUser['rut'];
        }
    }

?>