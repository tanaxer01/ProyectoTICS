<?php 
include_once('header.php');
include_once('navbar.php');
?>



<div class="margen_f">
    <center><a href="/"><img class="mb-4 " src="https://picsvg.com/example/owl.svg" alt="" width="72" height="72"></a></center>
    <h1 class="h3 mb-3 font-weight-normal text-center">NOMBRE DE EMPRESA</h1>
</div>

<div class="container">
    <div class="row">
        <div class="col">
            <div class="card mt-3" style="max-width: 18rem;">
                <div class="card-body">
                    <h5 class="card-title"> Revisar Mapa de la zona	</h5>
                    <p class="card-text text-secondary">
                    Es posible revisar los diferentes dispositivos en un mapa.
                    </p>
                    <form action="mapa.php" method="post">
                        <input type="hidden" name="id" value = "1"> 
                        <center><button class="btn bg-warning mt-2">Ver</button></center>
                    </form>
                </div>
            </div>
        </div>

        <div class="col">
            <div class="card mt-3" style="max-width: 18rem;">
                <div class="card-body">
                    <h5 class="card-title">Configurar datos de sensores</h5>
                    <form action="redirect.php" method="post">
                    <p class="card-text"> 
                    Temperatura:<!-- Temperatura: (colocar temperatura fijada)-->
                    <input class = "mt-2 mb-2" type="number" name="temperatura" placeholder="temperatura"required><br>
                    </p>
                    <p class="card-text"> 
                    Humedad:     <!--   (colocar Humedad fijada)--> 
                    <input class = "mt-2 mb-2" type="number" name="humedad" placeholder="humedad"required><br>
                    </p>
                    <p class="card-text"> 
                    Viento:  <!-- (colocar Viento fijada)--> 
                    <input class = "mt-2 mb-2" type="number" name="viento" placeholder="viento"required><br>                    
                    </p>
                    <center><button class="btn bg-warning" type="submit">Confirmar edición</button></center>
                    </form>
                </div>
            </div>
        </div>
        <div class="col">
            <div class="card mt-3" style="max-width: 18rem;">
                <div class="card-body">
                    <h5 class="card-title">Historigramas</h5>
                    <p class="card-text text-secondary"> 
                        En esta seccion es posible ver el registro de alertas a lo largo del tiempo.
                    </p>
                    <form action="historigrama.php" method="post">
                        <input type="hidden" name="id" value = "2">
                        <center><button class="btn bg-warning mt-2">Ver</button></center>
                    </form>
                </div>
            </div>
        </div>
    </div>
</div>


<div class="progress mt-1 mb-0" style="height: 7px;">
    <div class="progress-bar bg-warning" role="progressbar" style="width: 100%" aria-valuenow="50" aria-valuemin="0" aria-valuemax="100"></div>
</div>

<?php
include_once('footer.php');
?>