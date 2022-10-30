let hora = 0;
let minutos = 0;
let segundos = 0;

let interval;

function segundoDigito(digito){
    if(digito<10){
        return('0'+digito)
    }else{
        return(digito)
    }
}

function iniciar(){

    cronometro();
    interval = setInterval(cronometro,1000);

    console.log("foi");
    
}

function parar(){
    clearInterval(interval);
   
}

function zerar(){
    clearInterval(interval);
    segundos = 0;
    minutos = 0;
    hora = 0;
    
    document.getElementById('contador').innerText = segundoDigito(hora) + ':' + segundoDigito(minutos) + ':' + segundoDigito(segundos);
  
}


function cronometro(){

    segundos += 1;

    if(segundos == 60){
        segundos = 0;
        minutos += 1;

    }

    if(minutos == 60){
        minutos = 0;
        hora += 1;
    }

    document.getElementById('contador').innerText = segundoDigito(hora) + ':' + segundoDigito(minutos) + ':' + segundoDigito(segundos);

}