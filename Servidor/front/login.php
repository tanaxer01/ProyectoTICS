<?php include_once('header.php');?>

<?php 
$conn= pg_connect("host=localhost dbname=tics user=postgres password=123 port= 5432") or die('No se ha podido conectar: ' . pg_last_error());

if(isset($_POST['submit'])&&!empty($_POST['submit'])){
    
    $sql ="select * from personas where usuario = '".pg_escape_string($_POST['user'])."' and pass ='".pg_escape_string($_POST['password'])."'";
    $data = pg_query($conn,$sql); 
    $login_check = pg_num_rows($data);
    if($login_check > 0){ 
        
        echo "Login Successfully";   
        header('Location: /tics/index.php'); 
    }else{
        
        echo "Error en usuario o contraseña";
    }
}

?>


<div class=" margen ">
    <form action="" class= "form-signin" method="post">
        <h1>Login </h1>
        <input type="text" name="user" id="user" class="form-control inp " placeholder="ingrese usuario" required>
        <input type="password" name="password" id="password" class="form-control inp  " placeholder="ingrese contraseña" required>
        <input type="submit" name="submit" value="Ingresar" class="btn btn-primary ">
    </form>
</div>




<?php include_once('footer.php');?>