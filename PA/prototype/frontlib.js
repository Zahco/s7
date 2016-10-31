function sendLog(log) {
  $.ajax({
    type: 'POST',
    url: $("meta[data-log-url]").attr("data-log-url"),
    data: {data: log},
    success: function(data) {
      console.log(data);
    },
    error: function(data) {
      console.error(data);
    }
  });
}
