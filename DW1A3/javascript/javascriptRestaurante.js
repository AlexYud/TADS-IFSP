function LimparErro() {
  outPrecoErr.innerHTML = "";
  outConsumoErr.innerHTML = "";
}

function VerificarInput(precoKg, consumo) {
  try {
    saidaCalc.style.display = 'none';
    saidaDad.style.display = 'none';
    var preco = (precoKg.value).trim();
    var consu = (consumo.value).trim();

    if (preco == '' || preco <= 0) {
      LimparErro();
      saidaErr.style.display = 'block';
      divConsumoErr.style.display = 'none';
      divPrecoErr.style.display = 'block';
      outPrecoErr.innerHTML = "Campo inválido.";
      precoKg.focus();
      return false;
    }
    if (consu == '' || consu <= 0) {
      LimparErro();
      saidaErr.style.display = 'block';
      divPrecoErr.style.display = 'none';
      divConsumoErr.style.display = 'block';
      outConsumoErr.innerHTML = "Campo inválido.";
      consumo.focus();
      return false;
    }

    ArmazenarPeso(consu);

    return true;

  } catch (error) {
    alert(error);
    return false;
  }
}

function Calcular() {
  try {
    if (VerificarInput(precoKg, consumo)) {
      saidaErr.style.display = 'none';
      saidaCalc.style.display = 'block';
      if (consumo.value >= 1000) {
        let valor = precoKg.value;
        ArmazenarVenda(consumo.value, valor);
        let formatado = Number(valor).toLocaleString('pt-BR', { style: 'currency', currency: 'BRL' });
        outValor.innerHTML = formatado;
        btDados.style.display = 'block';
      } else {
        let valor = precoKg.value * (consumo.value / 1000);
        ArmazenarVenda(consumo.value, valor);
        let formatado = valor.toLocaleString('pt-BR', { style: 'currency', currency: 'BRL' });
        outValor.innerHTML = formatado;
        btDados.style.display = 'block';
      }
    }
  } catch (error) {
    alert(error);
  }
}

function ArmazenarPeso(consumo) {
  try {
    let maiorP = localStorage.getItem("peso");
    if (Number(consumo) > Number(maiorP)) {
      localStorage.setItem("peso", consumo);
    }
  } catch (error) {
    alert(error);
  }
}

function ArmazenarVenda(consumo, valor) {
  try {
    lista.push(
      {
        gramas: consumo,
        total: valor
      }
    );
  } catch (error) {
    alert(error);
  }
}

function LimpaTabela() {
  try {
    while (tabela.childElementCount > 1) {
      tabela.lastChild.remove();
    }
  } catch (error) {
    alert(error);
  }
}

function CriaTabela() {
  try {
    for (i = 0; i < lista.length; i++) {
      var tr = document.createElement("tr");
      tabela.appendChild(tr);
      var td = document.createElement("td");
      tr.appendChild(td);
      td.innerHTML = lista[i].gramas + " g";
      var td2 = document.createElement("td");
      tr.appendChild(td2);
      let formatado = Number(lista[i].total).toLocaleString('pt-BR', { style: 'currency', currency: 'BRL' });
      td2.innerHTML = formatado;
    }
  } catch (error) {
    alert(error);
  }
}

function SomarTotal() {
  try {
    var total = 0;
    for (i = 0; i < lista.length; i++) {
      total += Number(lista[i].total);
    }
    return total;
  } catch (error) {
    alert(error);
  }
}

function ListarVendas() {
  try {
    saidaErr.style.display = 'none';
    saidaCalc.style.display = 'none';
    saidaDad.style.display = 'block';
    LimpaTabela();
    CriaTabela();
    let formatado = Number(SomarTotal()).toLocaleString('pt-BR', { style: 'currency', currency: 'BRL' });
    outTotal.innerHTML = formatado;
    if (localStorage.getItem("peso") == null) {
      outPesoMax.innerHTML = " -- ";
    } else {
      outPesoMax.innerHTML = localStorage.getItem("peso") + " g";
    }
    
  } catch (error) {
    alert(error);
  }
}

var lista = [];
var precoKg = document.getElementById("precoKg");
var consumo = document.getElementById("consumo");
var outValor = document.getElementById("outValor");
var outPrecoErr = document.getElementById("outPrecoErr");
var outConsumoErr = document.getElementById("outConsumoErr");
var outTotal = document.getElementById("outTotal");
var outPesoMax = document.getElementById("outPesoMax");
var btDados = document.getElementById("btDados");
var btCalcular = document.getElementById("btCalcular");
var divPrecoErr = document.getElementById("divPrecoErr");
var divConsumoErr = document.getElementById("divConsumoErr");
var body = document.getElementById("body");
var tabela = document.getElementById("tabela");
var saidaErr = document.getElementById("saidaErr");
var saidaDad = document.getElementById("saidaDad");
var saidaCalc = document.getElementById("saidaCalc");

body.addEventListener("load", localStorage.removeItem("peso"));
btCalcular.addEventListener("click", Calcular);
btDados.addEventListener("click", ListarVendas);