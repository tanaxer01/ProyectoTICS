
<!DOCTYPE html>
<html lang="en">
	<head>
		<meta charset="UTF-8">
		<meta name="viewport" content="width=device-width, initial-scale=1.0">
		<link rel="stylesheet" href="style.css">
		<link rel="stylesheet" href="https://cdn.jsdelivr.net/npm/bootstrap@4.5.3/dist/css/bootstrap.min.css" integrity="sha384-TX8t27EcRE3e/ihU7zmQxVncDAy5uIKz4rEkgIXeMed4M0jlfIDPvg6uqKI2xXr2" crossorigin="anonymous">
		<link rel="stylesheet" type="text/css" href="https://stackpath.bootstrapcdn.com/bootstrap/4.4.1/css/bootstrap.min.css">
<link rel="stylesheet" type="text/css" href="https://pixinvent.com/stack-responsive-bootstrap-4-admin-template/app-assets/css/bootstrap-extended.min.css">
<link rel="stylesheet" type="text/css" href="https://pixinvent.com/stack-responsive-bootstrap-4-admin-template/app-assets/fonts/simple-line-icons/style.min.css">
<link rel="stylesheet" type="text/css" href="https://pixinvent.com/stack-responsive-bootstrap-4-admin-template/app-assets/css/colors.min.css">
<link href="https://fonts.googleapis.com/css?family=Montserrat&display=swap" rel="stylesheet">
		<title>Vitals Project</title>
	</head>
	<body><section id="main">
			<nav class="navbar navbar-expand-lg navbar-light bg-light">
				<a class="navbar-brand" href="index.php">Vitals</a>
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

			<section>
			<div class="container">
				<div class="row">
					<div class="col d-flex justify-content-center pt-3">
					<h1>SELECCIONA TU PLANTA</h1>
					</div>
				</div>
			</div>
			</section>

            
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
								<h5 class="card-title">
								Planta Carnivora								</h5>
								<p class="card-text text-secondary">
								Humedad Interna: 85 <br>
								Humedad Externa: 90 <br>
								Temperatura Interna: 21 <br>
								Temperatura Externa: 20 <br>
								Luz: 70								<br>

								</p>
								<form action="redirect.php" method="post">
								<input type="hidden" name="humedad" value="85" />
								<input type="hidden" name="temperatura" value="21" />

								<button class="btn bg-warning" type="submit">Agregar planta</button>
								</form>
								<form action="actualizar.php" method="post">
								<input type="hidden" name="id" value = "3">
								<button class="btn bg-warning mt-2">Editar datos</button>
								</form>
							</div>
						</div>
				</div>
		
		<div class="col">

		<div class="card mt-3" style="max-width: 18rem;">
            <div class="card-body">
                <h5 class="card-title">
                Aspidistra								</h5>
                <p class="card-text text-secondary">
                Humedad Interna: 95 <br>
                Humedad Externa: 90 <br>
                Temperatura Interna: 21 <br>
                Temperatura Externa: 15 <br>
                Luz: 60								<br>

                </p>
                <form action="redirect.php" method="post">
                <input type="hidden" name="humedad" value="95" />
                <input type="hidden" name="temperatura" value="21" />

                <button class="btn bg-warning" type="submit">Agregar planta</button>
                </form>
                <form action="actualizar.php" method="post">
                <input type="hidden" name="id" value = "4">
                <button class="btn bg-warning mt-2">Editar datos</button>
                </form>
            </div>
		    </div>
				</div>
		
			</div>

			</div>


			</div>

<script src="https://code.jquery.com/jquery-3.5.1.slim.min.js" integrity="sha384-DfXdz2htPH0lsSSs5nCTpuj/zy4C+OGpamoFVy38MVBnE+IbbVYUew+OrCXaRkfj" crossorigin="anonymous"></script>
		<script src="https://cdn.jsdelivr.net/npm/bootstrap@4.5.3/dist/js/bootstrap.bundle.min.js" integrity="sha384-ho+j7jyWK8fNQe+A12Hb8AhRq26LrZ/JpcUGGOn+Y7RsweNrtN/tE3MoK7ZeZDyx" crossorigin="anonymous"></script>
	</body>
</html>