<?php 
include_once('header.php');
?>
<div class="margen_f">
    <center><a href="/"><img class="mb-4 " src="https://picsvg.com/example/owl.svg" alt="" width="72" height="72"></a></center>
    <h1 class="h3 mb-3 font-weight-normal text-center">NOMBRE DE EMPRESA</h1>
</div>
<h2 class="text-center">Configuración</h2>
<div class="">
    <form action="" class="form-signin ">
        <h3>Temperatura</h3>
        <input type="number" id="temperatura" class="form-control margen" placeholder="T°" required autofocus>
        <h3>Humedad</h3>
        <input type="number" id="humedad" class="form-control margen" placeholder="%" required autofocus>
        <h3>Viento</h3>
        <input type="number" id="viento" class="form-control margen" placeholder="%" required autofocus>
        <button class="btn btn-lg btn-primary btn-block margen_boton" type="submit">Cambiar</button>
    </form>
</div>


<?php
include_once('footer.php');
?>