let myapp = {
    myfunction : () => Neutralino.settings.getSettings((data) => {
        document.getElementById('info').innerHTML = `${data.appname} is running on port ${data.appport}`;
    }, () => {

    })
};

window.onload = () => {
    myapp.myfunction();
};