console.log('START blobsaver injection');

window.oxide = oxide;

window.URL.createObjectURL = function(obj) {
    // TODO check if the obj is a blob

    console.log('blobsaver createObjectURL interceptor');

    var reader = new FileReader();
    reader.readAsDataURL(obj);
    reader.onloadend = function() {
        console.log('blobsaver createObjectURL sending message');
        window.oxide.sendMessage('createObjectURL', {base64data: reader.result});
    };

    throw 'stop'; // Throw an error here to stop execution (continuing execution would likely result in an error from the download manager)
};

console.log('END blobsaver injection');
