function PpEntrada() {
  try {
    ppe = Number(entrada.value);
    let formatadoE = ppe.toLocaleString('pt-BR', { style: 'currency', currency: 'BRL' });
    return " Entrada - " + formatadoE;
  } catch (error) {
    alert(error);
  }
}

function PpResto() {
  try {
    ppr = (preco.value - entrada.value)/24;
    let formatadoR = ppr.toLocaleString('pt-BR', { style: 'currency', currency: 'BRL' });
    return " Parcela - " + formatadoR + " (x24)";
  } catch (error) {
    alert(error);
  }
}

function Pv() {
  try {
    pv = preco.value - (preco.value * (desconto.value/100));
    let formatadoV = pv.toLocaleString('pt-BR', { style: 'currency', currency: 'BRL' });
    outPv.innerHTML = " " + formatadoV;
  } catch (error) {
    alert(error);
  }
} 

function Pp() {
  try {
    outPp1.innerHTML = PpEntrada();
    outPp2.innerHTML = PpResto();
  } catch (error) {
    alert(error);
  }
}

function LimparErro() {
  outMarcaErr.innerHTML = "";
  outModeloErr.innerHTML = "";
  outAnoErr.innerHTML = "";
  outPrecoErr.innerHTML = "";
  outDescErr.innerHTML = "";
  outEntradaErr.innerHTML = "";
}

function FormataData() {
  var data = new Date();
  var dia = data.getDate();
  var mes = (data.getMonth() + 1);
  var ano = data.getFullYear();
  var horas = data.getHours();
  var minutos = data.getMinutes();
  return dia + " / " + mes + " / " + ano + " - " + horas + " : " + minutos + " h";
}

function VerificarInput(marca, modelo, ano, preco, desconto, entrada) {
  try {
    saidaCalc.style.display = 'none';
    saidaDad.style.display = 'none';
    var marc = (marca.value).trim();
    var model = (modelo.value).trim();
    var an = (ano.value).trim();
    var prec = (preco.value).trim();
    var descont = (desconto.value).trim();
    var entrad = (entrada.value).trim();

    if (marc == '') {
      LimparErro();
      saidaErr.style.display = 'block';
      divMarcaErr.style.display = 'block';
      divModeloErr.style.display = 'none';
      divAnoErr.style.display = 'none';
      divPrecoErr.style.display = 'none';
      divDescErr.style.display = 'none';
      divEntradaErr.style.display = 'none';
      outMarcaErr.innerHTML = "Campo inválido.";
      marca.focus();
      return false;
    }
    if (model == '') {
      LimparErro();
      saidaErr.style.display = 'block';
      divModeloErr.style.display = 'block';
      divMarcaErr.style.display = 'none';
      divAnoErr.style.display = 'none';
      divPrecoErr.style.display = 'none';
      divDescErr.style.display = 'none';
      divEntradaErr.style.display = 'none';
      outModeloErr.innerHTML = "Campo inválido.";
      modelo.focus();
      return false;
    }
    if (an == '' || an > 2022 || an < 1950) {
      LimparErro();
      saidaErr.style.display = 'block';
      divAnoErr.style.display = 'block';
      divModeloErr.style.display = 'none';
      divMarcaErr.style.display = 'none';
      divPrecoErr.style.display = 'none';
      divDescErr.style.display = 'none';
      divEntradaErr.style.display = 'none';
      outAnoErr.innerHTML = "Campo inválido.";
      ano.focus();
      return false;
    }
    if (prec == '' || prec < 20000) {
      LimparErro();
      saidaErr.style.display = 'block';
      divPrecoErr.style.display = 'block';
      divModeloErr.style.display = 'none';
      divAnoErr.style.display = 'none';
      divMarcaErr.style.display = 'none';
      divDescErr.style.display = 'none';
      divEntradaErr.style.display = 'none';
      outPrecoErr.innerHTML = "Campo inválido. Preço menor que R$ 20.000,00";
      preco.focus();
      return false;
    }
    if (descont == '' || descont <= 0 || descont >= 100) {
      LimparErro();
      saidaErr.style.display = 'block';
      divDescErr.style.display = 'block';
      divModeloErr.style.display = 'none';
      divAnoErr.style.display = 'none';
      divPrecoErr.style.display = 'none';
      divMarcaErr.style.display = 'none';
      divEntradaErr.style.display = 'none';
      outDescErr.innerHTML = "Percentagem inválida";
      desconto.focus();
      return false;
    }
    if (entrad == '' || entrad >= prec) {
      LimparErro();
      saidaErr.style.display = 'block';
      divEntradaErr.style.display = 'block';
      divModeloErr.style.display = 'none';
      divAnoErr.style.display = 'none';
      divPrecoErr.style.display = 'none';
      divDescErr.style.display = 'none';
      divMarcaErr.style.display = 'none';
      outEntradaErr.innerHTML = "Campo inválido. Entrada maior ou igual ao preço.";
      entrada.focus();
      return false;
    }

    carro.marca = marc;
    carro.modelo = model;
    carro.ano = an;
    carro.preco = prec;
    carro.data = FormataData();

    return true;

  } catch (error) {
    alert(error);
    return false;
  }
}

function Mostrar() {
  try {
    if (VerificarInput(marca, modelo, ano, preco, desconto, entrada)) {
      saidaErr.style.display = 'none';
      saidaDad.style.display = 'block';
      let preco = Number(carro.preco).toLocaleString('pt-BR', { style: 'currency', currency: 'BRL' });
      outMarca.innerHTML = carro.marca;
      outModelo.innerHTML = carro.modelo;
      outAno.innerHTML = carro.ano;
      outPreco.innerHTML = preco;
      outData.innerHTML = carro.data;
    }
  } catch (error) {
    alert("Erro");
  }
}

function Calcular() {
  try {
    if (VerificarInput(marca, modelo, ano, preco, desconto, entrada)) {
      saidaErr.style.display = 'none';
      saidaCalc.style.display = 'block';
      Pv();
      Pp();
    } 
  } catch (error) {
    alert("Erro");
  }
}

var carro = {
  marca: "",
  modelo: "",
  ano: 0,
  preco: 0,
  data: null
}

var marca = document.getElementById("marca");
var modelo = document.getElementById("modelo");
var ano = document.getElementById("ano");
var preco = document.getElementById("preco");
var desconto = document.getElementById("desconto");
var entrada = document.getElementById("entrada");
var btDados = document.getElementById("btDados");
var outMarca = document.getElementById("outMarca");
var outModelo = document.getElementById("outModelo");
var outAno = document.getElementById("outAno");
var outPreco = document.getElementById("outPreco");
var outMarcaErr = document.getElementById("outMarcaErr");
var outModeloErr = document.getElementById("outModeloErr");
var outAnoErr = document.getElementById("outAnoErr");
var outPrecoErr = document.getElementById("outPrecoErr");
var outDescErr = document.getElementById("outDescErr");
var outEntradaErr = document.getElementById("outEntradaErr");
var outData = document.getElementById("outData");
var divMarcaErr = document.getElementById("divMarcaErr");
var divModeloErr = document.getElementById("divModeloErr");
var divAnoErr = document.getElementById("divAnoErr");
var divPrecoErr = document.getElementById("divPrecoErr");
var divDescErr = document.getElementById("divDescErr");
var divEntradaErr = document.getElementById("divEntradaErr");
var btCalcular = document.getElementById("btCalcular");
var outPv = document.getElementById("outPv");
var ulPp = document.getElementById("ulPp");
var outPp1 = document.getElementById("outPp1");
var outPp2 = document.getElementById("outPp2");
var saidaErr = document.getElementById("saidaErr");
var saidaDad = document.getElementById("saidaDad");
var saidaCalc = document.getElementById("saidaCalc");

btDados.addEventListener("click", Mostrar);
btCalcular.addEventListener("click", Calcular);