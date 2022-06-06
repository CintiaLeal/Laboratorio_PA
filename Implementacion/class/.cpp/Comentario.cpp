//#include "../"

Comentario::Comentario(int idComentario, string texto, dtFechaHora fechaHora){
    this->idComentario = idComentario;
    this->texto = texto;
    this->fechaHora = fechaHora;    
}
Comentario::Comentario(){

}

int Comentario::getIdComentario(){
    return this->idComentario;
}

string Comentario::getTexto(){
    return this->texto;
}

dtFechaHora Comentario::getFechaHora(){
    return this->fechaHora;
}
//No se puede cambiar el id o si?
void Comentario::setIdComentario(int idComentario){
    this->idComentario = idComentario;
}

void Comentario::setTexto(string texto){
    this->texto = texto;
}
//No se puede cambiar la fecha y hora o si?
void Comentario::setFechaHora(dtFechaHora fechaHora){
    this->fechaHora = fechaHora;
}

void eliminarComentario(){
    //Implementar
}