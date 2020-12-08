<section id="main">
  <nav class="navbar navbar-expand-lg navbar-light bg-light">
    <a class="navbar-brand" href="index.php">FireFire</a>
    <button class="navbar-toggler" type="button" data-toggle="collapse" data-target="#navbarNavDropdown" aria-controls="navbarNavDropdown" aria-expanded="false" aria-label="Toggle navigation">
      <span class="navbar-toggler-icon"></span>
    </button>
    <div class="collapse navbar-collapse" id="navbarNavDropdown">
      <ul class="navbar-nav">
        <li class="nav-item">
          <a class="nav-link" href="index.php">Inicio <span class="sr-only">(current)</span></a>
        </li>
        <li class="nav-item">
          <a class="nav-link" href="dispositivos.php">Dispositivo</a>
        </li>
        <li class="nav-item active">
          <a class="nav-link" href="plantas.php">Plantas</a>
        </li>
        <li class="nav-item">
          <a class="nav-link" href="contacto.php">Contacto</a>
        </li>
        <li class="nav-item">
          <a class="nav-link" href="acerca.php">Acerca de</a>
        </li>
      </ul>
    </div>
  </nav>

<div class="container">
    <div class="row">
        <div class="col">
            <div class="card mt-3" style="max-width: 18rem;">
                <div class="card-body">
                    <h5 class="card-title">
                    Pomelo								</h5>
                    <p class="card-text text-secondary">
                    Humedad Interna: 85 <br>
                    Humedad Externa: 90 <br>
                    Temperatura Interna: 10 <br>
                    Temperatura Externa: 15 <br>
                    Luz: 90								<br>

                    </p>
                    <form action="redirect.php" method="post">
                    <input type="hidden" name="humedad" value="85" />
                    <input type="hidden" name="temperatura" value="10" />

                    <button class="btn bg-warning" type="submit">Agregar planta</button>
                    </form>
                    <form action="actualizar.php" method="post">
                    <input type="hidden" name="id" value = "1">
                    <button class="btn bg-warning mt-2">Editar datos</button>
                    </form>
                </div>
            </div>
        </div>
        <div class="col">
            <div class="card mt-3" style="max-width: 18rem;">
                <div class="card-body">
                    <h5 class="card-title">Costa Mediterranea</h5>
                    <p class="card-text text-secondary"> 
                        Humedad Interna: 85 <br>
                        Humedad Externa: 90 <br>
                        Temperatura Interna: 21 <br>
                        Temperatura Externa: 20 <br>
                        Luz: 80<br>
                    </p>
                    <form action="redirect.php" method="post">
                        <input type="hidden" name="humedad" value="85" />
                        <input type="hidden" name="temperatura" value="21" />
                        <button class="btn bg-warning" type="submit">Agregar planta</button>
                    </form>
                    <form action="actualizar.php" method="post">
                        <input type="hidden" name="id" value = "2">
                        <button class="btn bg-warning mt-2">Editar datos</button>
                    </form>
                </div>
            </div>
        </div>
        <div class="col">
            <div class="card mt-3" style="max-width: 18rem;">
                <div class="card-body">
                    <h5 class="card-title">Costa Mediterranea</h5>
                    <p class="card-text text-secondary"> 
                        Humedad Interna: 85 <br>
                        Humedad Externa: 90 <br>
                        Temperatura Interna: 21 <br>
                        Temperatura Externa: 20 <br>
                        Luz: 80<br>
                    </p>
                    <form action="redirect.php" method="post">
                        <input type="hidden" name="humedad" value="85" />
                        <input type="hidden" name="temperatura" value="21" />
                        <button class="btn bg-warning" type="submit">Agregar planta</button>
                    </form>
                    <form action="actualizar.php" method="post">
                        <input type="hidden" name="id" value = "2">
                        <button class="btn bg-warning mt-2">Editar datos</button>
                    </form>
                </div>
            </div>
        </div>
        <div class="col">
            <div class="card mt-3" style="max-width: 18rem;">
                <div class="card-body">
                    <h5 class="card-title">Costa Mediterranea</h5>
                    <p class="card-text text-secondary"> 
                        Humedad Interna: 85 <br>
                        Humedad Externa: 90 <br>
                        Temperatura Interna: 21 <br>
                        Temperatura Externa: 20 <br>
                        Luz: 80<br>
                    </p>
                    <form action="redirect.php" method="post">
                        <input type="hidden" name="humedad" value="85" />
                        <input type="hidden" name="temperatura" value="21" />
                        <button class="btn bg-warning" type="submit">Agregar planta</button>
                    </form>
                    <form action="actualizar.php" method="post">
                        <input type="hidden" name="id" value = "2">
                        <button class="btn bg-warning mt-2">Editar datos</button>
                    </form>
                </div>
            </div>
        </div>
    </div>
</div>




<div class="col">
  <div class="card mt-3" style="max-width: 18rem;">
      <div class="card-body">
          <h5 class="card-title">Costa Mediterranea</h5>
          <p class="card-text text-secondary"> 
              Humedad Interna: 85 <br>
              Humedad Externa: 90 <br>
              Temperatura Interna: 21 <br>
              Temperatura Externa: 20 <br>
              Luz: 80<br>
          </p>
          <form action="redirect.php" method="post">
              <input type="hidden" name="humedad" value="85" />
              <input type="hidden" name="temperatura" value="21" />
              <button class="btn bg-warning" type="submit">Agregar planta</button>
          </form>
          <form action="actualizar.php" method="post">
              <input type="hidden" name="id" value = "2">
              <button class="btn bg-warning mt-2">Editar datos</button>
          </form>
      </div>
  </div>
</div>


<div class= "form-signin">
    <ul class="list-group">
        <li class="list-group-item text-center"><a href="config.php"> Revisar mapa de la zona </a> </li>
        <li class="list-group-item text-center"><a href="config.php"> Configuración de sensores </a></li>
        <li class="list-group-item text-center"> <a href="config.php"> Histogramas </a> </li>
    </ul>
</div>