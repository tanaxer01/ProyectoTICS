<?php 
include_once('header.php');
?>
<div class="centrado_login">
    <form class="form-signin centrado_login" method  ='POST'>
        <center><img class="mb-4 " src="https://picsvg.com/example/owl.svg" alt="" width="72" height="72"></center>
        <h1 class="h3 mb-3 font-weight-normal text-center">Please sign in</h1>
        <label for="inputEmail" class="sr-only">Email address</label>
        <input type="email" id="inputEmail" class="form-control margen" placeholder="Usuario" required autofocus>
        <label for="inputPassword" class="sr-only">Password</label>
        <input type="password" id="inputPassword" class="form-control margen" placeholder="Contraseña" required>
        <button class="btn btn-lg btn-primary btn-block margen_boton" type="submit">Entrar</button>
    </form>
</div>

<?php
include_once('footer.php')
?>