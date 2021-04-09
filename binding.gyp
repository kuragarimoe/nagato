{
    "targets": [
        {
            "target_name": "nagatosrc",
            "sources": [
                "src/module.cc",
                "src/packets/packet.cc"
            ],
            "include_dirs" : [
                "<!(node -e \"require('nan')\")"
            ]
        }
    ]
}