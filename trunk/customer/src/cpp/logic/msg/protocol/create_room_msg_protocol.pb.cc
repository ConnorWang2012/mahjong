﻿// Generated by the protocol buffer compiler.  DO NOT EDIT!
// source: create_room_msg_protocol.proto

#define INTERNAL_SUPPRESS_PROTOBUF_FIELD_DEPRECATION
#include "create_room_msg_protocol.pb.h"

#include <algorithm>

#include <google/protobuf/stubs/common.h>
#include <google/protobuf/stubs/once.h>
#include <google/protobuf/io/coded_stream.h>
#include <google/protobuf/wire_format_lite_inl.h>
#include <google/protobuf/descriptor.h>
#include <google/protobuf/generated_message_reflection.h>
#include <google/protobuf/reflection_ops.h>
#include <google/protobuf/wire_format.h>
// @@protoc_insertion_point(includes)

namespace gamer {
namespace protocol {

namespace {

const ::google::protobuf::Descriptor* CreateRoomMsgProtocol_descriptor_ = NULL;
const ::google::protobuf::internal::GeneratedMessageReflection*
  CreateRoomMsgProtocol_reflection_ = NULL;

}  // namespace


void protobuf_AssignDesc_create_5froom_5fmsg_5fprotocol_2eproto() {
  protobuf_AddDesc_create_5froom_5fmsg_5fprotocol_2eproto();
  const ::google::protobuf::FileDescriptor* file =
    ::google::protobuf::DescriptorPool::generated_pool()->FindFileByName(
      "create_room_msg_protocol.proto");
  GOOGLE_CHECK(file != NULL);
  CreateRoomMsgProtocol_descriptor_ = file->message_type(0);
  static const int CreateRoomMsgProtocol_offsets_[7] = {
    GOOGLE_PROTOBUF_GENERATED_MESSAGE_FIELD_OFFSET(CreateRoomMsgProtocol, room_owner_id_),
    GOOGLE_PROTOBUF_GENERATED_MESSAGE_FIELD_OFFSET(CreateRoomMsgProtocol, rounds_num_),
    GOOGLE_PROTOBUF_GENERATED_MESSAGE_FIELD_OFFSET(CreateRoomMsgProtocol, players_num_),
    GOOGLE_PROTOBUF_GENERATED_MESSAGE_FIELD_OFFSET(CreateRoomMsgProtocol, score_gold_),
    GOOGLE_PROTOBUF_GENERATED_MESSAGE_FIELD_OFFSET(CreateRoomMsgProtocol, score_diamond_),
    GOOGLE_PROTOBUF_GENERATED_MESSAGE_FIELD_OFFSET(CreateRoomMsgProtocol, room_cards_num_),
    GOOGLE_PROTOBUF_GENERATED_MESSAGE_FIELD_OFFSET(CreateRoomMsgProtocol, room_id_),
  };
  CreateRoomMsgProtocol_reflection_ =
    new ::google::protobuf::internal::GeneratedMessageReflection(
      CreateRoomMsgProtocol_descriptor_,
      CreateRoomMsgProtocol::default_instance_,
      CreateRoomMsgProtocol_offsets_,
      GOOGLE_PROTOBUF_GENERATED_MESSAGE_FIELD_OFFSET(CreateRoomMsgProtocol, _has_bits_[0]),
      GOOGLE_PROTOBUF_GENERATED_MESSAGE_FIELD_OFFSET(CreateRoomMsgProtocol, _unknown_fields_),
      -1,
      ::google::protobuf::DescriptorPool::generated_pool(),
      ::google::protobuf::MessageFactory::generated_factory(),
      sizeof(CreateRoomMsgProtocol));
}

namespace {

GOOGLE_PROTOBUF_DECLARE_ONCE(protobuf_AssignDescriptors_once_);
inline void protobuf_AssignDescriptorsOnce() {
  ::google::protobuf::GoogleOnceInit(&protobuf_AssignDescriptors_once_,
                 &protobuf_AssignDesc_create_5froom_5fmsg_5fprotocol_2eproto);
}

void protobuf_RegisterTypes(const ::std::string&) {
  protobuf_AssignDescriptorsOnce();
  ::google::protobuf::MessageFactory::InternalRegisterGeneratedMessage(
    CreateRoomMsgProtocol_descriptor_, &CreateRoomMsgProtocol::default_instance());
}

}  // namespace

void protobuf_ShutdownFile_create_5froom_5fmsg_5fprotocol_2eproto() {
  delete CreateRoomMsgProtocol::default_instance_;
  delete CreateRoomMsgProtocol_reflection_;
}

void protobuf_AddDesc_create_5froom_5fmsg_5fprotocol_2eproto() {
  static bool already_here = false;
  if (already_here) return;
  already_here = true;
  GOOGLE_PROTOBUF_VERIFY_VERSION;

  ::google::protobuf::DescriptorPool::InternalAddGeneratedFile(
    "\n\036create_room_msg_protocol.proto\022\016gamer."
    "protocol\"\261\001\n\025CreateRoomMsgProtocol\022\025\n\rro"
    "om_owner_id\030\001 \002(\r\022\022\n\nrounds_num\030\002 \002(\r\022\023\n"
    "\013players_num\030\003 \002(\r\022\022\n\nscore_gold\030\004 \002(\r\022\025"
    "\n\rscore_diamond\030\005 \001(\r\022\031\n\016room_cards_num\030"
    "\006 \001(\r:\0010\022\022\n\007room_id\030\007 \001(\r:\0010", 228);
  ::google::protobuf::MessageFactory::InternalRegisterGeneratedFile(
    "create_room_msg_protocol.proto", &protobuf_RegisterTypes);
  CreateRoomMsgProtocol::default_instance_ = new CreateRoomMsgProtocol();
  CreateRoomMsgProtocol::default_instance_->InitAsDefaultInstance();
  ::google::protobuf::internal::OnShutdown(&protobuf_ShutdownFile_create_5froom_5fmsg_5fprotocol_2eproto);
}

// Force AddDescriptors() to be called at static initialization time.
struct StaticDescriptorInitializer_create_5froom_5fmsg_5fprotocol_2eproto {
  StaticDescriptorInitializer_create_5froom_5fmsg_5fprotocol_2eproto() {
    protobuf_AddDesc_create_5froom_5fmsg_5fprotocol_2eproto();
  }
} static_descriptor_initializer_create_5froom_5fmsg_5fprotocol_2eproto_;

// ===================================================================

#ifndef _MSC_VER
const int CreateRoomMsgProtocol::kRoomOwnerIdFieldNumber;
const int CreateRoomMsgProtocol::kRoundsNumFieldNumber;
const int CreateRoomMsgProtocol::kPlayersNumFieldNumber;
const int CreateRoomMsgProtocol::kScoreGoldFieldNumber;
const int CreateRoomMsgProtocol::kScoreDiamondFieldNumber;
const int CreateRoomMsgProtocol::kRoomCardsNumFieldNumber;
const int CreateRoomMsgProtocol::kRoomIdFieldNumber;
#endif  // !_MSC_VER

CreateRoomMsgProtocol::CreateRoomMsgProtocol()
  : ::google::protobuf::Message() {
  SharedCtor();
  // @@protoc_insertion_point(constructor:gamer.protocol.CreateRoomMsgProtocol)
}

void CreateRoomMsgProtocol::InitAsDefaultInstance() {
}

CreateRoomMsgProtocol::CreateRoomMsgProtocol(const CreateRoomMsgProtocol& from)
  : ::google::protobuf::Message() {
  SharedCtor();
  MergeFrom(from);
  // @@protoc_insertion_point(copy_constructor:gamer.protocol.CreateRoomMsgProtocol)
}

void CreateRoomMsgProtocol::SharedCtor() {
  _cached_size_ = 0;
  room_owner_id_ = 0u;
  rounds_num_ = 0u;
  players_num_ = 0u;
  score_gold_ = 0u;
  score_diamond_ = 0u;
  room_cards_num_ = 0u;
  room_id_ = 0u;
  ::memset(_has_bits_, 0, sizeof(_has_bits_));
}

CreateRoomMsgProtocol::~CreateRoomMsgProtocol() {
  // @@protoc_insertion_point(destructor:gamer.protocol.CreateRoomMsgProtocol)
  SharedDtor();
}

void CreateRoomMsgProtocol::SharedDtor() {
  if (this != default_instance_) {
  }
}

void CreateRoomMsgProtocol::SetCachedSize(int size) const {
  GOOGLE_SAFE_CONCURRENT_WRITES_BEGIN();
  _cached_size_ = size;
  GOOGLE_SAFE_CONCURRENT_WRITES_END();
}
const ::google::protobuf::Descriptor* CreateRoomMsgProtocol::descriptor() {
  protobuf_AssignDescriptorsOnce();
  return CreateRoomMsgProtocol_descriptor_;
}

const CreateRoomMsgProtocol& CreateRoomMsgProtocol::default_instance() {
  if (default_instance_ == NULL) protobuf_AddDesc_create_5froom_5fmsg_5fprotocol_2eproto();
  return *default_instance_;
}

CreateRoomMsgProtocol* CreateRoomMsgProtocol::default_instance_ = NULL;

CreateRoomMsgProtocol* CreateRoomMsgProtocol::New() const {
  return new CreateRoomMsgProtocol;
}

void CreateRoomMsgProtocol::Clear() {
#define OFFSET_OF_FIELD_(f) (reinterpret_cast<char*>(      \
  &reinterpret_cast<CreateRoomMsgProtocol*>(16)->f) - \
   reinterpret_cast<char*>(16))

#define ZR_(first, last) do {                              \
    size_t f = OFFSET_OF_FIELD_(first);                    \
    size_t n = OFFSET_OF_FIELD_(last) - f + sizeof(last);  \
    ::memset(&first, 0, n);                                \
  } while (0)

  if (_has_bits_[0 / 32] & 127) {
    ZR_(room_owner_id_, room_id_);
  }

#undef OFFSET_OF_FIELD_
#undef ZR_

  ::memset(_has_bits_, 0, sizeof(_has_bits_));
  mutable_unknown_fields()->Clear();
}

bool CreateRoomMsgProtocol::MergePartialFromCodedStream(
    ::google::protobuf::io::CodedInputStream* input) {
#define DO_(EXPRESSION) if (!(EXPRESSION)) goto failure
  ::google::protobuf::uint32 tag;
  // @@protoc_insertion_point(parse_start:gamer.protocol.CreateRoomMsgProtocol)
  for (;;) {
    ::std::pair< ::google::protobuf::uint32, bool> p = input->ReadTagWithCutoff(127);
    tag = p.first;
    if (!p.second) goto handle_unusual;
    switch (::google::protobuf::internal::WireFormatLite::GetTagFieldNumber(tag)) {
      // required uint32 room_owner_id = 1;
      case 1: {
        if (tag == 8) {
          DO_((::google::protobuf::internal::WireFormatLite::ReadPrimitive<
                   ::google::protobuf::uint32, ::google::protobuf::internal::WireFormatLite::TYPE_UINT32>(
                 input, &room_owner_id_)));
          set_has_room_owner_id();
        } else {
          goto handle_unusual;
        }
        if (input->ExpectTag(16)) goto parse_rounds_num;
        break;
      }

      // required uint32 rounds_num = 2;
      case 2: {
        if (tag == 16) {
         parse_rounds_num:
          DO_((::google::protobuf::internal::WireFormatLite::ReadPrimitive<
                   ::google::protobuf::uint32, ::google::protobuf::internal::WireFormatLite::TYPE_UINT32>(
                 input, &rounds_num_)));
          set_has_rounds_num();
        } else {
          goto handle_unusual;
        }
        if (input->ExpectTag(24)) goto parse_players_num;
        break;
      }

      // required uint32 players_num = 3;
      case 3: {
        if (tag == 24) {
         parse_players_num:
          DO_((::google::protobuf::internal::WireFormatLite::ReadPrimitive<
                   ::google::protobuf::uint32, ::google::protobuf::internal::WireFormatLite::TYPE_UINT32>(
                 input, &players_num_)));
          set_has_players_num();
        } else {
          goto handle_unusual;
        }
        if (input->ExpectTag(32)) goto parse_score_gold;
        break;
      }

      // required uint32 score_gold = 4;
      case 4: {
        if (tag == 32) {
         parse_score_gold:
          DO_((::google::protobuf::internal::WireFormatLite::ReadPrimitive<
                   ::google::protobuf::uint32, ::google::protobuf::internal::WireFormatLite::TYPE_UINT32>(
                 input, &score_gold_)));
          set_has_score_gold();
        } else {
          goto handle_unusual;
        }
        if (input->ExpectTag(40)) goto parse_score_diamond;
        break;
      }

      // optional uint32 score_diamond = 5;
      case 5: {
        if (tag == 40) {
         parse_score_diamond:
          DO_((::google::protobuf::internal::WireFormatLite::ReadPrimitive<
                   ::google::protobuf::uint32, ::google::protobuf::internal::WireFormatLite::TYPE_UINT32>(
                 input, &score_diamond_)));
          set_has_score_diamond();
        } else {
          goto handle_unusual;
        }
        if (input->ExpectTag(48)) goto parse_room_cards_num;
        break;
      }

      // optional uint32 room_cards_num = 6 [default = 0];
      case 6: {
        if (tag == 48) {
         parse_room_cards_num:
          DO_((::google::protobuf::internal::WireFormatLite::ReadPrimitive<
                   ::google::protobuf::uint32, ::google::protobuf::internal::WireFormatLite::TYPE_UINT32>(
                 input, &room_cards_num_)));
          set_has_room_cards_num();
        } else {
          goto handle_unusual;
        }
        if (input->ExpectTag(56)) goto parse_room_id;
        break;
      }

      // optional uint32 room_id = 7 [default = 0];
      case 7: {
        if (tag == 56) {
         parse_room_id:
          DO_((::google::protobuf::internal::WireFormatLite::ReadPrimitive<
                   ::google::protobuf::uint32, ::google::protobuf::internal::WireFormatLite::TYPE_UINT32>(
                 input, &room_id_)));
          set_has_room_id();
        } else {
          goto handle_unusual;
        }
        if (input->ExpectAtEnd()) goto success;
        break;
      }

      default: {
      handle_unusual:
        if (tag == 0 ||
            ::google::protobuf::internal::WireFormatLite::GetTagWireType(tag) ==
            ::google::protobuf::internal::WireFormatLite::WIRETYPE_END_GROUP) {
          goto success;
        }
        DO_(::google::protobuf::internal::WireFormat::SkipField(
              input, tag, mutable_unknown_fields()));
        break;
      }
    }
  }
success:
  // @@protoc_insertion_point(parse_success:gamer.protocol.CreateRoomMsgProtocol)
  return true;
failure:
  // @@protoc_insertion_point(parse_failure:gamer.protocol.CreateRoomMsgProtocol)
  return false;
#undef DO_
}

void CreateRoomMsgProtocol::SerializeWithCachedSizes(
    ::google::protobuf::io::CodedOutputStream* output) const {
  // @@protoc_insertion_point(serialize_start:gamer.protocol.CreateRoomMsgProtocol)
  // required uint32 room_owner_id = 1;
  if (has_room_owner_id()) {
    ::google::protobuf::internal::WireFormatLite::WriteUInt32(1, this->room_owner_id(), output);
  }

  // required uint32 rounds_num = 2;
  if (has_rounds_num()) {
    ::google::protobuf::internal::WireFormatLite::WriteUInt32(2, this->rounds_num(), output);
  }

  // required uint32 players_num = 3;
  if (has_players_num()) {
    ::google::protobuf::internal::WireFormatLite::WriteUInt32(3, this->players_num(), output);
  }

  // required uint32 score_gold = 4;
  if (has_score_gold()) {
    ::google::protobuf::internal::WireFormatLite::WriteUInt32(4, this->score_gold(), output);
  }

  // optional uint32 score_diamond = 5;
  if (has_score_diamond()) {
    ::google::protobuf::internal::WireFormatLite::WriteUInt32(5, this->score_diamond(), output);
  }

  // optional uint32 room_cards_num = 6 [default = 0];
  if (has_room_cards_num()) {
    ::google::protobuf::internal::WireFormatLite::WriteUInt32(6, this->room_cards_num(), output);
  }

  // optional uint32 room_id = 7 [default = 0];
  if (has_room_id()) {
    ::google::protobuf::internal::WireFormatLite::WriteUInt32(7, this->room_id(), output);
  }

  if (!unknown_fields().empty()) {
    ::google::protobuf::internal::WireFormat::SerializeUnknownFields(
        unknown_fields(), output);
  }
  // @@protoc_insertion_point(serialize_end:gamer.protocol.CreateRoomMsgProtocol)
}

::google::protobuf::uint8* CreateRoomMsgProtocol::SerializeWithCachedSizesToArray(
    ::google::protobuf::uint8* target) const {
  // @@protoc_insertion_point(serialize_to_array_start:gamer.protocol.CreateRoomMsgProtocol)
  // required uint32 room_owner_id = 1;
  if (has_room_owner_id()) {
    target = ::google::protobuf::internal::WireFormatLite::WriteUInt32ToArray(1, this->room_owner_id(), target);
  }

  // required uint32 rounds_num = 2;
  if (has_rounds_num()) {
    target = ::google::protobuf::internal::WireFormatLite::WriteUInt32ToArray(2, this->rounds_num(), target);
  }

  // required uint32 players_num = 3;
  if (has_players_num()) {
    target = ::google::protobuf::internal::WireFormatLite::WriteUInt32ToArray(3, this->players_num(), target);
  }

  // required uint32 score_gold = 4;
  if (has_score_gold()) {
    target = ::google::protobuf::internal::WireFormatLite::WriteUInt32ToArray(4, this->score_gold(), target);
  }

  // optional uint32 score_diamond = 5;
  if (has_score_diamond()) {
    target = ::google::protobuf::internal::WireFormatLite::WriteUInt32ToArray(5, this->score_diamond(), target);
  }

  // optional uint32 room_cards_num = 6 [default = 0];
  if (has_room_cards_num()) {
    target = ::google::protobuf::internal::WireFormatLite::WriteUInt32ToArray(6, this->room_cards_num(), target);
  }

  // optional uint32 room_id = 7 [default = 0];
  if (has_room_id()) {
    target = ::google::protobuf::internal::WireFormatLite::WriteUInt32ToArray(7, this->room_id(), target);
  }

  if (!unknown_fields().empty()) {
    target = ::google::protobuf::internal::WireFormat::SerializeUnknownFieldsToArray(
        unknown_fields(), target);
  }
  // @@protoc_insertion_point(serialize_to_array_end:gamer.protocol.CreateRoomMsgProtocol)
  return target;
}

int CreateRoomMsgProtocol::ByteSize() const {
  int total_size = 0;

  if (_has_bits_[0 / 32] & (0xffu << (0 % 32))) {
    // required uint32 room_owner_id = 1;
    if (has_room_owner_id()) {
      total_size += 1 +
        ::google::protobuf::internal::WireFormatLite::UInt32Size(
          this->room_owner_id());
    }

    // required uint32 rounds_num = 2;
    if (has_rounds_num()) {
      total_size += 1 +
        ::google::protobuf::internal::WireFormatLite::UInt32Size(
          this->rounds_num());
    }

    // required uint32 players_num = 3;
    if (has_players_num()) {
      total_size += 1 +
        ::google::protobuf::internal::WireFormatLite::UInt32Size(
          this->players_num());
    }

    // required uint32 score_gold = 4;
    if (has_score_gold()) {
      total_size += 1 +
        ::google::protobuf::internal::WireFormatLite::UInt32Size(
          this->score_gold());
    }

    // optional uint32 score_diamond = 5;
    if (has_score_diamond()) {
      total_size += 1 +
        ::google::protobuf::internal::WireFormatLite::UInt32Size(
          this->score_diamond());
    }

    // optional uint32 room_cards_num = 6 [default = 0];
    if (has_room_cards_num()) {
      total_size += 1 +
        ::google::protobuf::internal::WireFormatLite::UInt32Size(
          this->room_cards_num());
    }

    // optional uint32 room_id = 7 [default = 0];
    if (has_room_id()) {
      total_size += 1 +
        ::google::protobuf::internal::WireFormatLite::UInt32Size(
          this->room_id());
    }

  }
  if (!unknown_fields().empty()) {
    total_size +=
      ::google::protobuf::internal::WireFormat::ComputeUnknownFieldsSize(
        unknown_fields());
  }
  GOOGLE_SAFE_CONCURRENT_WRITES_BEGIN();
  _cached_size_ = total_size;
  GOOGLE_SAFE_CONCURRENT_WRITES_END();
  return total_size;
}

void CreateRoomMsgProtocol::MergeFrom(const ::google::protobuf::Message& from) {
  GOOGLE_CHECK_NE(&from, this);
  const CreateRoomMsgProtocol* source =
    ::google::protobuf::internal::dynamic_cast_if_available<const CreateRoomMsgProtocol*>(
      &from);
  if (source == NULL) {
    ::google::protobuf::internal::ReflectionOps::Merge(from, this);
  } else {
    MergeFrom(*source);
  }
}

void CreateRoomMsgProtocol::MergeFrom(const CreateRoomMsgProtocol& from) {
  GOOGLE_CHECK_NE(&from, this);
  if (from._has_bits_[0 / 32] & (0xffu << (0 % 32))) {
    if (from.has_room_owner_id()) {
      set_room_owner_id(from.room_owner_id());
    }
    if (from.has_rounds_num()) {
      set_rounds_num(from.rounds_num());
    }
    if (from.has_players_num()) {
      set_players_num(from.players_num());
    }
    if (from.has_score_gold()) {
      set_score_gold(from.score_gold());
    }
    if (from.has_score_diamond()) {
      set_score_diamond(from.score_diamond());
    }
    if (from.has_room_cards_num()) {
      set_room_cards_num(from.room_cards_num());
    }
    if (from.has_room_id()) {
      set_room_id(from.room_id());
    }
  }
  mutable_unknown_fields()->MergeFrom(from.unknown_fields());
}

void CreateRoomMsgProtocol::CopyFrom(const ::google::protobuf::Message& from) {
  if (&from == this) return;
  Clear();
  MergeFrom(from);
}

void CreateRoomMsgProtocol::CopyFrom(const CreateRoomMsgProtocol& from) {
  if (&from == this) return;
  Clear();
  MergeFrom(from);
}

bool CreateRoomMsgProtocol::IsInitialized() const {
  if ((_has_bits_[0] & 0x0000000f) != 0x0000000f) return false;

  return true;
}

void CreateRoomMsgProtocol::Swap(CreateRoomMsgProtocol* other) {
  if (other != this) {
    std::swap(room_owner_id_, other->room_owner_id_);
    std::swap(rounds_num_, other->rounds_num_);
    std::swap(players_num_, other->players_num_);
    std::swap(score_gold_, other->score_gold_);
    std::swap(score_diamond_, other->score_diamond_);
    std::swap(room_cards_num_, other->room_cards_num_);
    std::swap(room_id_, other->room_id_);
    std::swap(_has_bits_[0], other->_has_bits_[0]);
    _unknown_fields_.Swap(&other->_unknown_fields_);
    std::swap(_cached_size_, other->_cached_size_);
  }
}

::google::protobuf::Metadata CreateRoomMsgProtocol::GetMetadata() const {
  protobuf_AssignDescriptorsOnce();
  ::google::protobuf::Metadata metadata;
  metadata.descriptor = CreateRoomMsgProtocol_descriptor_;
  metadata.reflection = CreateRoomMsgProtocol_reflection_;
  return metadata;
}


// @@protoc_insertion_point(namespace_scope)

}  // namespace protocol
}  // namespace gamer

// @@protoc_insertion_point(global_scope)
