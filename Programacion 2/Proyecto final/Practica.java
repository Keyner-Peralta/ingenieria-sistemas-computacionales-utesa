public class Practica {
	public void main(String[] args)
	{
		PantallaOLED miPantalla = new PantallaOLED(50, true);

		miPantalla.sonidoDeEncendido();
		miPantalla.imagen();
    }		
}

interface Sonido{
	public void sonidoDeEncendido();
}

abstract class Televisor {

    public abstract void imagen();
}

class PantallaOLED extends Televisor implements Sonido{
	private int volumen;
	private boolean encendida;

	public PantallaOLED(int volumen, boolean encendida) {
		if(volumen > 100){
			volumen = 100;
		}else if(volumen < 0){
			volumen = 0;
		}	
        
		this.volumen = volumen;
		this.encendida = encendida;

        if(encendida){
            sonidoDeEncendido();
        }
	}
	
	public int getVolumen(){
		return volumen;
	}
	public void setVolumen(int volumen){
		this.volumen = volumen;
	}

	public boolean getEncendida(){
		return encendida;
	}
	public void setEncendida(boolean encendida){
		this.encendida = encendida;
	}

	@Override
	public void imagen(){
		System.out.println("|=============================|");
		System.out.println("|=                           =|");
		System.out.println("|=                           =|");
		System.out.println("|=       LG corporation      =|");
		System.out.println("|=                           =|");
		System.out.println("|=                           =|");	
		System.out.println("|=============================|");	
	}

	@Override
	public void sonidoDeEncendido(){
		System.out.println("tin-tin-tiiin");
	}
}

class MiniTV extends PantallaOLED{
	
	public MiniTV(int volumen, boolean encendida){
		super(volumen, encendida);	
	}

	@Override
	public void imagen(){
		System.out.println("|=============================|");
		System.out.println("|=                           =|");
		System.out.println("|=                           =|");
		System.out.println("|=      Mini TV LG CORP      =|");
		System.out.println("|=                           =|");
		System.out.println("|=                           =|");	
		System.out.println("|=============================|");	
	}
	@Override
	public void sonidoDeEncendido(){
		System.out.println("ra-ra-raaa");
	}
}

